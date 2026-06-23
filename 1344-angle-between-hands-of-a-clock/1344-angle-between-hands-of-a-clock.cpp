class Solution {
public:
    double angleClock(int hour, int minutes) {
        // minute hand: 360/60 = 6 degrees per minute
        double minuteAngle = minutes * 6.0;

        // hour hand: 360/12 = 30 degrees per hour
        // + moves with minutes: 0.5 degrees per minute
        double hourAngle = (hour % 12) * 30.0 + minutes * 0.5;

        double diff = abs(hourAngle - minuteAngle);

        // return smaller angle
        return min(diff, 360.0 - diff);
    }
};