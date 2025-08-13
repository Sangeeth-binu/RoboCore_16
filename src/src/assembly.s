
MAIN_LOOP:

    LW R1, 0x900(R0)
    BNE R1, R0, EMERGENCY_STOP
    
    LW R2, 0x400(R0)
    BNE R2, R0, EMERGENCY_AVOID
    
    LW R3, 0x910(R0)    # Control system timer
    LI R4, 10           # Control runs every 10ms
    BLT R3, R4, SKIP_CONTROL
    
    # Reset timer and run control
    LI R5, 0
    SW R5, 0x910(R0)    # Reset control timer
    CALL PID_CONTROL    # Run PID control
    CALL MOTOR_CONTROL_LOOP  # Update motors immediately
    
SKIP_CONTROL:
    # PRIORITY 2: SENSOR PROCESSING (Run every 50ms)
    LW R6, 0x911(R0)    # Sensor timer
    LI R7, 50           # Sensors run every 50ms
    BLT R6, R7, SKIP_SENSORS
    
    # Reset timer and run sensors
    LI R8, 0
    SW R8, 0x911(R0)    # Reset sensor timer
    CALL SENSOR_READ_LOOP  # Update all sensor readings
    
SKIP_SENSORS:
    # PRIORITY 3: NAVIGATION ALGORITHMS (Run every 100ms)
    LW R9, 0x912(R0)    # Navigation timer
    LI R10, 100         # Navigation runs every 100ms
    BLT R9, R10, SKIP_NAVIGATION
    
    # Reset timer and run navigation
    LI R11, 0
    SW R11, 0x912(R0)   # Reset navigation timer
    
    # Choose navigation algorithm based on mode
    LW R12, 0x800(R0)   # Read system mode
    LI R13, 1
    BEQ R12, R13, NAV_LINE_FOLLOW
    LI R13, 2
    BEQ R12, R13, NAV_MAZE_SOLVE
    JMP SKIP_NAVIGATION
    
NAV_LINE_FOLLOW:
    CALL LINE_FOLLOW
    JMP SKIP_NAVIGATION
    
NAV_MAZE_SOLVE:
    CALL MAZE_SOLVE
    
SKIP_NAVIGATION:
    # PRIORITY 4: COMMUNICATION (Run every 200ms - lowest priority)
    LW R14, 0x913(R0)   # Communication timer
    LI R15, 200         # Communication runs every 200ms
    BLT R14, R15, UPDATE_TIMERS
    
    # Reset timer and run communication
    LI R1, 0
    SW R1, 0x913(R0)    # Reset communication timer
    CALL ROBOT_COMM     # Handle robot communication
    
UPDATE_TIMERS:
    # Increment all timers (assuming 1ms system tick)
    LW R2, 0x910(R0)    # Control timer
    ADDI R2, R2, 1
    SW R2, 0x910(R0)
    
    LW R3, 0x911(R0)    # Sensor timer
    ADDI R3, R3, 1
    SW R3, 0x911(R0)
    
    LW R4, 0x912(R0)    # Navigation timer
    ADDI R4, R4, 1
    SW R4, 0x912(R0)
    
    LW R5, 0x913(R0)    # Communication timer
    ADDI R5, R5, 1
    SW R5, 0x913(R0)
    
    # Check for mode changes
    LW R6, 0x801(R0)    # Mode change request
    BEQ R6, R0, CONTINUE_LOOP
    
    # Handle mode change
    SW R6, 0x800(R0)    # Update current mode
    LI R7, 0
    SW R7, 0x801(R0)    # Clear mode change request
    
CONTINUE_LOOP:
    JMP MAIN_LOOP       # Continue the priority loop

# EMERGENCY HANDLERS
EMERGENCY_STOP:
    # Immediate motor shutdown
    LI R1, 0
    SW R1, 0x100(R0)    # Stop Motor 1
    SW R1, 0x101(R0)    # Stop Motor 2
    SW R1, 0x102(R0)    # Stop Motor 3
    SW R1, 0x103(R0)    # Stop Motor 4
    
    # Set emergency LED
    LI R2, 1
    SW R2, 0x920(R0)    # Emergency LED on
    
    # Wait for emergency clear
EMERGENCY_WAIT:
    LW R3, 0x900(R0)    # Check emergency flag
    BNE R3, R0, EMERGENCY_WAIT
    
    # Clear emergency LED and resume
    LI R4, 0
    SW R4, 0x920(R0)    # Emergency LED off
    JMP MAIN_LOOP

EMERGENCY_AVOID:
    # Collision avoidance override
    LW R1, 0x400(R0)    # Get obstacle direction
    
    # Reverse motors briefly
    LI R2, 100          # Reverse speed
    LI R3, 0
    
    # Direction-based avoidance
    LI R4, 1            # Front obstacle
    BEQ R1, R4, AVOID_FRONT
    LI R4, 2            # Right obstacle  
    BEQ R1, R4, AVOID_RIGHT
    LI R4, 4            # Left obstacle
    BEQ R1, R4, AVOID_LEFT
    JMP CLEAR_OBSTACLE
    
AVOID_FRONT:
    # Back up
    SW R3, 0x100(R0)    # Left motor reverse
    SW R3, 0x101(R0)    # Right motor reverse
    JMP AVOID_DELAY
    
AVOID_RIGHT:
    # Turn left
    SW R2, 0x100(R0)    # Left motor forward
    SW R3, 0x101(R0)    # Right motor stop
    JMP AVOID_DELAY
    
AVOID_LEFT:
    # Turn right
    SW R3, 0x100(R0)    # Left motor stop
    SW R2, 0x101(R0)    # Right motor forward
    
AVOID_DELAY:
    # Simple delay counter for avoidance maneuver
    LI R5, 1000         # Delay counter
AVOID_LOOP:
    SUBI R5, R5, 1
    BNE R5, R0, AVOID_LOOP
    
CLEAR_OBSTACLE:
    # Clear obstacle flag and resume
    LI R6, 0
    SW R6, 0x400(R0)    # Clear obstacle status
    JMP MAIN_LOOP

PID_CONTROL:
        LI R1, 2            # Proportional gain
    LI R2, 1           
    LI R3, 1            

    LW R4, 0x401(R0)
    LI R5, 100
    SUB R6, R5, R4
    LW R7, 0x500(R0)
    LW R8, 0x501(R0)
    MUL R9, R1, R6
    ADD R8, R8, R6      
    MUL R10, R2, R8     
    SUB R11, R6, R7  
    MUL R12, R3, R11   
 
    ADD R13, R9, R10   
    ADD R13, R13, R12  
    LI R14, 255
    BLT R13, R14, PID_VALID
    OR R13, R14, R0  
PID_VALID:
    LI R14, 0
    BGT R13, R14, PID_POSITIVE
    OR R13, R14, R0  
PID_POSITIVE:
    SW R13, 0x100(R0)
    SW R6, 0x500(R0)
    SW R8, 0x501(R0)
    RET

SENSOR_READ_LOOP:
    RET

LINE_FOLLOW:
    RET 

MAZE_SOLVE:
    RET

ROBOT_COMM:
    RET             

MOTOR_CONTROL_LOOP:
    RET            