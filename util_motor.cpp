#include "util_motor.h"
#include "pin_define.h"
#include "util_timer.h"

void motor_stop() {
    pwm_start(MOTOR_A_FORWARD, PWM_FREQUENCY, 0, RESOLUTION_10B_COMPARE_FORMAT);
    pwm_start(MOTOR_B_FORWARD, PWM_FREQUENCY, 0, RESOLUTION_10B_COMPARE_FORMAT);
    pwm_start(MOTOR_A_REVERSE, PWM_FREQUENCY, 0, RESOLUTION_10B_COMPARE_FORMAT);
    pwm_start(MOTOR_B_REVERSE, PWM_FREQUENCY, 0, RESOLUTION_10B_COMPARE_FORMAT);
    analogWriteFrequency(TIMER_FREQUENCY);
    delay(10);
}

void motor_pwm_stop() {
    pwm_stop(MOTOR_A_FORWARD);
    pwm_stop(MOTOR_B_FORWARD);
    pwm_stop(MOTOR_A_REVERSE);
    pwm_stop(MOTOR_B_REVERSE);
    analogWriteFrequency(TIMER_FREQUENCY);
    delay(10);
}

// 0 < speed < 1024

void motor_run(uint32_t speed) {
    pwm_start(MOTOR_A_FORWARD, PWM_FREQUENCY, speed, RESOLUTION_10B_COMPARE_FORMAT);
    pwm_start(MOTOR_B_FORWARD, PWM_FREQUENCY, speed + MOTOR_OFFSET, RESOLUTION_10B_COMPARE_FORMAT);
    pwm_start(MOTOR_A_REVERSE, PWM_FREQUENCY, 0, RESOLUTION_10B_COMPARE_FORMAT);
    pwm_start(MOTOR_B_REVERSE, PWM_FREQUENCY, 0, RESOLUTION_10B_COMPARE_FORMAT);
    analogWriteFrequency(TIMER_FREQUENCY);
    delay(10);
}

void motor_reverse(uint32_t speed) {
    pwm_start(MOTOR_A_FORWARD, PWM_FREQUENCY, 0, RESOLUTION_10B_COMPARE_FORMAT);
    pwm_start(MOTOR_B_FORWARD, PWM_FREQUENCY, 0, RESOLUTION_10B_COMPARE_FORMAT);
    pwm_start(MOTOR_A_REVERSE, PWM_FREQUENCY, speed, RESOLUTION_10B_COMPARE_FORMAT);
    pwm_start(MOTOR_B_REVERSE, PWM_FREQUENCY, speed + MOTOR_OFFSET, RESOLUTION_10B_COMPARE_FORMAT);
    analogWriteFrequency(TIMER_FREQUENCY);
    delay(10);
}

void motor_rotate_right(uint32_t speed) {
    pwm_start(MOTOR_A_FORWARD, PWM_FREQUENCY, speed, RESOLUTION_10B_COMPARE_FORMAT);
    pwm_start(MOTOR_B_REVERSE, PWM_FREQUENCY, speed + MOTOR_OFFSET, RESOLUTION_10B_COMPARE_FORMAT);
    pwm_start(MOTOR_A_REVERSE, PWM_FREQUENCY, 0, RESOLUTION_10B_COMPARE_FORMAT);
    pwm_start(MOTOR_B_FORWARD, PWM_FREQUENCY, 0, RESOLUTION_10B_COMPARE_FORMAT);
    analogWriteFrequency(TIMER_FREQUENCY);
    delay(10);
}

void motor_rotate_left(uint32_t speed) {
    pwm_start(MOTOR_A_REVERSE, PWM_FREQUENCY, speed, RESOLUTION_10B_COMPARE_FORMAT);
    pwm_start(MOTOR_B_FORWARD, PWM_FREQUENCY, speed + MOTOR_OFFSET, RESOLUTION_10B_COMPARE_FORMAT);
    pwm_start(MOTOR_A_FORWARD, PWM_FREQUENCY, 0, RESOLUTION_10B_COMPARE_FORMAT);
    pwm_start(MOTOR_B_REVERSE, PWM_FREQUENCY, 0, RESOLUTION_10B_COMPARE_FORMAT);
    analogWriteFrequency(TIMER_FREQUENCY);
    delay(10);
}