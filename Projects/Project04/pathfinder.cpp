#include <iostream>
#include <cstdio>
#include <vector>
#include "deque.hpp"
#include "lib/image.h"

// ----- Define Maze Settings -----
#define MAZE_START RED
#define MAZE_WALL BLACK
#define MAZE_SPACE WHITE
#define MAZE_GOAL GREEN


// ----- Define Datastructures -----
// Enum to store return types
enum ReturnStatus {
    Success,
    Failure
};
// Struct to store a position of the image
struct PixelPos {
    std::size_t x;
    std::size_t y;
};
// Struct to serve as a return type
struct MazeSolution {
    ReturnStatus status;
    PixelPos exit;
};

// ----- Prototypes -----
MazeSolution breadthFirstSearch(Image<Pixel>&, PixelPos&);
MazeSolution findStart(Image<Pixel>&);
bool isGoal(Image<Pixel>&, PixelPos&);
std::vector<PixelPos> getValidMoves(Image<Pixel>&, PixelPos&);
bool isMoveValid(Image<Pixel>&, PixelPos&);
int main(int argc, char *argv[]);

// ----- Helper Functions -----
// Function to perform breadth first search algorithm on an image
MazeSolution breadthFirstSearch(Image<Pixel> &image, PixelPos &start) {
    // Define helper varaibles
    MazeSolution result;
    PixelPos s = start;

    // Check for starting in end condition
    if (isGoal(image, s)) {
        result.status = Success;
        result.exit = s;
        return result;
    }

    // Declare frontier
    Deque<PixelPos> frontier;
    frontier.pushBack(s);

    // Declare explored (2d array of bools)
    bool explored[image.width()][image.height()];


    // Begin loop
    while (!frontier.isEmpty()) {
        // Pop next state
        s = frontier.front();
        frontier.popFront();

        // DEBUG:
        std::cout << "Evaluating at (" << s.x << ", " << s.y << ").\n";

        // Add state to explored
        explored[s.x][s.y] = true;

        // Get legal moves
        std::vector<PixelPos> moves = getValidMoves(image, s);

        // Iterate through legal moves
        for (std::size_t i = 0; i < moves.size(); i++) {
            PixelPos s_next = moves.at(i);
            // Check if it has already been explored
            if (explored[s_next.x][s_next.y]) {
                // Check if goal
                if (isGoal(image, s_next)) {
                    result.status = Success;
                    result.exit = s_next;
                    return result;
                }
                // Add to frontier
                frontier.pushBack(s_next);
            }
        }
    }

    // Must be failure
    result.status = Failure;
    result.exit = s;
    return result;
}

// Function to find starting position from image
MazeSolution findStart(Image<Pixel> &image) {
    MazeSolution result;
    for (std::size_t x = 0; x < image.width(); x++) {
        for (std::size_t y = 0; y < image.height(); y++) {
            if (image(x, y) == MAZE_START) {
                PixelPos pos;
                pos.x = x;
                pos.y = y;
                result.status = Success;
                result.exit = pos;
                return result;
            }
        }
    }

    // Got through entire maze without finding solution
    // Exit with failure
    PixelPos pos;
    pos.x = 0;
    pos.y = 0;
    result.status = Failure;
    result.exit = pos;
    return result;
}

// Function to determine if a pixel position is a goal
bool isGoal(Image<Pixel> &image, PixelPos &pos) {
    // Get borders
    std::size_t leftBorder = 0;
    std::size_t rightBorder = image.width() - 1;
    std::size_t topBorder = 0;
    std::size_t bottomBorder = image.height() - 1;

    // Check x
    if (pos.x == leftBorder || pos.x == rightBorder) {
        return true;
    }

    // Check y
    if (pos.y == topBorder || pos.y == bottomBorder) {
        return true;
    }

    // Not a goal
    return false;
}

// Function to determine a list of legal moves from a given position
std::vector<PixelPos> getValidMoves(Image<Pixel> &image, PixelPos &pos) {
    // Declare return array
    std::vector<PixelPos> moves;

    // Declare possible moves
    PixelPos up;
    up.x = pos.x;
    up.y = pos.y - 1;
    PixelPos down;
    down.x = pos.x;
    down.y = pos.y + 1;
    PixelPos left;
    left.x = pos.x - 1;
    left.y = pos.y;
    PixelPos right;
    right.x = pos.x + 1;
    right.y = pos.y;

    // Determine which moves are valid, and append them to the return list
    if (isMoveValid(image, up)) { moves.push_back(up); }
    if (isMoveValid(image, down)) { moves.push_back(down); }
    if (isMoveValid(image, left)) { moves.push_back(left); }
    if (isMoveValid(image, right)) { moves.push_back(right); }

    // Return vector
    return moves;
}

// Function to determine if a pixel position is valid
bool isMoveValid(Image<Pixel> &image, PixelPos &pos) {
    // Ensure position is within borders
    if (pos.x < 0 || pos.y < 0) {
        return false;
    }
    if (pos.x >= image.width() || pos.y >= image.height()) {
        return false;
    }

    // Ensure pixel is not black
    if (image(pos.x, pos.y) == MAZE_WALL) {
        return false;
    }

    // Position is valid to hold
    return true;
}

// Main function to handle CLI
int main(int argc, char *argv[])
{
    // Handle command-line arguments
    if (argc != 3) {
        std::cout << "Error: Usage: pathfinder"
                << "<input_image_filename> <output_image_filename>\n"
                << std::endl;
        return EXIT_FAILURE;
    }

    // Read images from files
    Image<Pixel> input = readFromFile(argv[1]);
    Image<Pixel> output;

    // Find starting point
    MazeSolution startSoln = findStart(input);
    if (startSoln.status == Failure) {
        // No start found, exit failure
        std::cout << "Error: No starting point found" << std::endl;
        return EXIT_FAILURE;
    }

    // Extract start point from solution to finding start point
    PixelPos start = startSoln.exit;

    // Find solution
    MazeSolution exitSoln = breadthFirstSearch(input, start);

    // Check solution's validity
    if (exitSoln.status == Failure) {
        // Some error arose
        std::cout << "Error: Error finding exit, unsolvable?" << std::endl;
        return EXIT_FAILURE;
    }

    // Extract nearest exit point from solution
    PixelPos exit = exitSoln.exit;

    // Set exit pixel green
    output = input;
    output(exit.x, exit.y) = MAZE_GOAL;

    // Write solution to file
    writeToFile(output, argv[2]);

    // End with success
    return EXIT_SUCCESS;
}
