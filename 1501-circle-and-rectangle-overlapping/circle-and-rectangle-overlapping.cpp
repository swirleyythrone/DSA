class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // Clamp the circle center to the rectangle bounds
        int closestX = max(x1, min(xCenter, x2));
        int closestY = max(y1, min(yCenter, y2));
        
        // Calculate the squared distance from the circle center to the closest point
        int dx = xCenter - closestX;
        int dy = yCenter - closestY;
        
        return dx * dx + dy * dy <= radius * radius;
    }
};
