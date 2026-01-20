#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>

using namespace std;

// Define Shape as a list of (dx, dy) offsets from the top-left position
using Shape = vector<pair<int, int>>;

// Base shapes for the five block types
vector<Shape> base_shapes = {
    {{0,0}, {0,1}, {1,0}, {1,1}},  // Block 0: 2x2 square (4 cells)
    {{0,0}, {0,1}, {1,0}},         // Block 1: L-shape in 2x2 (3 cells)
    {{0,0}, {0,1}},                // Block 2: Horizontal bar (2 cells)
    {{0,0}, {1,0}},                // Block 3: Vertical bar (2 cells)
    {{0,0}}                        // Block 4: Single cell (1 cell)
};

/**
 * Rotate a shape by k * 90° clockwise (k = 0, 1, 2, 3)
 */
Shape rotate(const Shape& shape, int k) {
    if (k == 0) return shape;
    Shape rotated;
    for (auto [x, y] : shape) {
        if (k == 1) {         // 90°: (x,y) -> (y, -x)
            rotated.push_back({y, -x});
        } else if (k == 2) {  // 180°: (x,y) -> (-x, -y)
            rotated.push_back({-x, -y});
        } else if (k == 3) {  // 270°: (x,y) -> (-y, x)
            rotated.push_back({-y, x});
        }
    }
    // Shift to ensure all coordinates are non-negative
    int min_x = INT_MAX, min_y = INT_MAX;
    for (auto [x, y] : rotated) {
        min_x = min(min_x, x);
        min_y = min(min_y, y);
    }
    for (auto& p : rotated) {
        p.first -= min_x;
        p.second -= min_y;
    }
    return rotated;
}

/**
 * Check if a shape can be placed at position (r, c) on the grid
 */
bool can_place(const vector<vector<int>>& grid, const Shape& shape, int r, int c, int N) {
    for (auto [dx, dy] : shape) {
        int nx = r + dx;
        int ny = c + dy;
        if (nx >= N || ny >= N || grid[nx][ny] == 1) {
            return false; // Out of bounds or cell occupied
        }
    }
    return true;
}

/**
 * Place a shape at position (r, c) on the grid
 */
void place(vector<vector<int>>& grid, const Shape& shape, int r, int c) {
    for (auto [dx, dy] : shape) {
        grid[r + dx][c + dy] = 1;
    }
}

/**
 * Clear all fully filled rows and columns simultaneously
 */
void clear_filled(vector<vector<int>>& grid, int N) {
    vector<bool> filled_rows(N, true);
    vector<bool> filled_cols(N, true);
    // Check which rows and columns are not fully filled
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 0) {
                filled_rows[i] = false;
                filled_cols[j] = false;
            }
        }
    }
    // Clear filled rows
    for (int i = 0; i < N; i++) {
        if (filled_rows[i]) {
            for (int j = 0; j < N; j++) {
                grid[i][j] = 0;
            }
        }
    }
    // Clear filled columns
    for (int j = 0; j < N; j++) {
        if (filled_cols[j]) {
            for (int i = 0; i < N; i++) {
                grid[i][j] = 0;
            }
        }
    }
}

/**
 * Count the number of empty cells in the grid
 */
int count_empty(const vector<vector<int>>& grid, int N) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 0) count++;
        }
    }
    return count;
}

int main() {
    // Read input from console
    int N, a, b, c, d, e, f;
    cin >> N >> a >> b >> c >> d >> e >> f;

    // Initialize N x N grid with all cells empty (0)
    vector<vector<int>> grid(N, vector<int>(N, 0));
    int moves = 0;

    while (true) {
        // Determine block type and rotation
        int block_type = c % 5;
        int k = f % 4; // Rotation index (0=0°, 1=90°, 2=180°, 3=270°)
        Shape shape = rotate(base_shapes[block_type], k);

        // Calculate shape dimensions
        int height = 0, width = 0;
        for (auto [dx, dy] : shape) {
            height = max(height, dx + 1);
            width = max(width, dy + 1);
        }

        // Find all possible placement positions
        vector<pair<int, int>> possible_positions;
        for (int r = 0; r <= N - height; r++) {
            for (int c = 0; c <= N - width; c++) {
                if (can_place(grid, shape, r, c, N)) {
                    possible_positions.push_back({r, c});
                }
            }
        }

        // If no placement is possible, game ends
        if (possible_positions.empty()) {
            break;
        }

        // Choose the position that maximizes empty cells after clearing
        pair<int, int> best_pos = {-1, -1};
        int max_empty = -1;
        for (auto [r, c] : possible_positions) {
            auto temp_grid = grid;
            place(temp_grid, shape, r, c);
            clear_filled(temp_grid, N);
            int empty_count = count_empty(temp_grid, N);
            if (empty_count > max_empty) {
                max_empty = empty_count;
                best_pos = {r, c};
            }
        }

        // Place the block at the best position and update the grid
        place(grid, shape, best_pos.first, best_pos.second);
        clear_filled(grid, N);

        // Update c and f for the next move
        c = (c ^ a) + b;
        f = (f ^ d) + e;
        moves++;
    }

    // Output the total number of moves
    cout << moves << endl;

    return 0;
}