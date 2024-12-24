#include <GL/glut.h>

// Function to draw a rectangle
void drawRectangle(float x1, float y1, float x2, float y2, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
    glEnd();
}

// Function to draw an approximated circle using small rectangles
void drawApproxCircle(float cx, float cy, float radius, float r, float g, float b) {
    glColor3f(r, g, b);
    int numSegments = 36; // Number of segments
    float segmentSize = radius * 2.0f / numSegments;
    for (int i = 0; i < numSegments; i++) {
        for (int j = 0; j < numSegments; j++) {
            float x = cx - radius + i * segmentSize;
            float y = cy - radius + j * segmentSize;
            float dist = (x - cx) * (x - cx) + (y - cy) * (y - cy);
            if (dist <= radius * radius) {
                drawRectangle(x, y, x + segmentSize, y + segmentSize, r, g, b);
            }
        }
    }
}

// Function to draw a simple star
void drawStar(float cx, float cy, float size, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLES);

    // Hardcoded vertex positions for a 5-pointed star relative to center
    float vertices[10][2] = {
        {0.0f, size}, {-0.2f * size, 0.2f * size}, // Top point, left upper
        {-size, 0.2f * size}, {-0.3f * size, -0.1f * size}, // Left side points
        {-0.5f * size, -size}, {0.0f, -0.4f * size},        // Bottom left
        {0.5f * size, -size}, {0.3f * size, -0.1f * size},  // Bottom right
        {size, 0.2f * size}, {0.2f * size, 0.2f * size}     // Right side points
    };

    for (int i = 0; i < 10; i++) {
        glVertex2f(cx, cy);                              // Center
        glVertex2f(cx + vertices[i][0], cy + vertices[i][1]); // Current vertex
        glVertex2f(cx + vertices[(i + 1) % 10][0], cy + vertices[(i + 1) % 10][1]); // Next vertex
    }
    glEnd();
}

// Function to draw the Ethiopian flag
void drawFlag() {
    // Draw the pole
    drawRectangle(-0.9, -1.0, -0.85, 1.0, 0.5, 0.5, 0.5);

    // Draw the three horizontal stripes
    float stripeHeight = 2.0f / 3.0f; // Height of each stripe
    drawRectangle(-0.85, 1.0, 0.85, 1.0 - stripeHeight, 0.0, 0.5, 0.0); // Green
    drawRectangle(-0.85, 1.0 - stripeHeight, 0.85, 1.0 - 2 * stripeHeight, 1.0, 1.0, 0.0); // Yellow
    drawRectangle(-0.85, 1.0 - 2 * stripeHeight, 0.85, -1.0, 0.9, 0.0, 0.0); // Red

    // Draw the blue circle in the center
    drawApproxCircle(-0.5, 0.33, 0.25, 0.0, 0.0, 1.0);

    // Draw the yellow star in the center
    drawStar(-0.5, 0.33, 0.1, 1.0, 1.0, 0.0);
}

// Display callback function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawFlag();

    glFlush();
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Ethiopian Flag with Pole");
    glClearColor(1.0, 1.0, 1.0, 1.0); // White background
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
