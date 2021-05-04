// 733. Flood Fill

// An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

// Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

// To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

// At the end, return the modified image.

// Example 1:
// Input:
// image = [[1,1,1],[1,1,0],[1,0,1]]
// sr = 1, sc = 1, newColor = 2
// Output: [[2,2,2],[2,2,0],[2,0,1]]
// Explanation:
// From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected
// by a path of the same color as the starting pixel are colored with the new color.
// Note the bottom corner is not colored 2, because it is not 4-directionally connected
// to the starting pixel.
// Note:

// The length of image and image[0] will be in the range [1, 50].
// The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
// The value of each color in image[i][j] and newColor will be an integer in [0, 65535].

bool isSafe(vector<vector<int>>& image, int sr, int sc, vector<vector<bool>>& visited, int m, int n, int color) {
	if ((sr < m && sr >= 0) && (sc < n && sc >= 0) && (visited[sr][sc] == false) && (image[sr][sc] == color)) {
		return true;
	}
	return false;
}
void floodFill(vector<vector<int>>& image, int sr, int sc, int newColor, vector<vector<bool>>& visited, int m, int n, int color) {
	if (isSafe(image, sr, sc, visited, m, n, color) == false) {
		return;
	}
	visited[sr][sc] = true;
	image[sr][sc] = newColor;
	int mov[][2] = {
		{0, 1},
		{1, 0},
		{ -1, 0},
		{0, -1}
	};

	for (int i = 0; i < 4; ++i) {
		if (isSafe(image, sr + mov[i][0], sc + mov[i][1], visited, m, n, color) == true) {
			floodFill(image, sr + mov[i][0], sc + mov[i][1], newColor, visited, m, n, color);
		}
	}
	return;
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
	int m = image.size();
	int n = image[0].size();
	vector<vector<bool>> visited(m, vector<bool> (n, false));
	if ((sr >= 0 ) && (sr < m) && (sc >= 0 && sc < n)) {
		int color = image[sr][sc];
		floodFill(image, sr, sc, newColor, visited, m, n, color);
	}

	return image;
}


int main() {
	int m, n, sr, sc, newColor;
	cin >> m >> n;
	vector<vector<int>> image(n, vector<int> (m, 0));
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> image[i][j];
		}
	}
	cin >> sr >> sc >> newColor;


	image = floodFill(image, sr, sc, newColor);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << image[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}