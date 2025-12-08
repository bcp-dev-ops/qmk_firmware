mouse_xy_t apply_mouse_acceleration(mouse_xy_t movement) {
    float speed = sqrt(pow(movement.x, 2) + pow(movement.y, 2));

    if (speed > ACCEL_OFFSET) {
        float factor = 1.0f + pow(speed - ACCEL_OFFSET, 2) * 0.001f * ACCEL_SLOPE;

        if (factor > ACCEL_LIMIT) {
            factor = ACCEL_LIMIT;
        }

        movement.x = (int16_t)(movement.x * factor);
        movement.y = (int16_t)(movement.y * factor);
    }

    return movement;
}
