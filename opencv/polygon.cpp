/*
sudo apt update
sudo apt-get install libopencv-dev
*/
#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;
/**
 * 182 std::vector<cv::Point>⋅polygonVertices⋅=⋅{{404,⋅236},↴
 *   1 │⋅⋅⋅│⋅⋅⋅│⋅⋅⋅│⋅⋅⋅│⋅⋅⋅│⋅⋅⋅│⋅⋅⋅│⋅⋅⋅│⋅⋅⋅│⋅⋅⋅│⋅{275,⋅171},↴
 *     2 │⋅⋅⋅│⋅⋅⋅│⋅⋅⋅│⋅⋅⋅│⋅⋅⋅│⋅⋅⋅│⋅⋅⋅│⋅⋅⋅│⋅⋅⋅│⋅⋅⋅│⋅{273,⋅39},↴
 *       3 │⋅⋅⋅│⋅⋅⋅│⋅⋅⋅│⋅⋅⋅│⋅⋅⋅│⋅⋅⋅│⋅⋅⋅│⋅⋅⋅│⋅⋅⋅│⋅⋅⋅│⋅{415,⋅78},↴
 *         4 │⋅⋅⋅│⋅⋅⋅│⋅⋅⋅│⋅⋅⋅│⋅⋅⋅│⋅⋅⋅│⋅⋅⋅│⋅⋅⋅│⋅⋅⋅│⋅⋅⋅│⋅{405,⋅236}};↴
 *
 */
//std::vector<Point> polygonVertices = {{404,236},{275,171},{273,39},{415,78},{405,232}};
std::vector<Point>polygonVertices = {{ 408,234 }, { 290,179 }, { 347,122 }, { 414,135 }};
//std::vector<Point>polygonVertices =  {{ 282,175 }, { 316,148 }, { 312,95 }, { 289,96 }};
Mat img;

// Mouse callback function
void onMouse(int event, int x, int y, int flags, void* userdata)
{
    if (event == EVENT_LBUTTONDOWN)
    {
        // Add the current point to the polygon vertices
        polygonVertices.push_back(Point(x, y));
        
	    for(auto &point : polygonVertices) {
	    	std::cout << "{" << point.x << ","<< point.y <<"},";
	    }
        // Check if the mouse cursor is inside the polygon
        // Draw the polygon on the image
        polylines(img, polygonVertices, true, Scalar(0, 255, 255), 2);
        // Display the image in a window
        imshow("Example", img);
    }
	if(polygonVertices.size() > 1) {
        double dist = pointPolygonTest(polygonVertices, Point(x, y), true);
        if (dist >= 0)
        {
			for(auto point : polygonVertices) {
				std::cout << "{ " << point.x << "," << point.y << " }, ";
			}
            std::cout << "Mouse is inside polygon" << std::endl;
        }
        else
        {
            std::cout << "Mouse is outside polygon" << std::endl;
        } 
	}
}

int main(int argc, char** argv)
{
    // Load an image from disk
    img = imread("../img.png");

	if(argc > 1) {
		polygonVertices.clear();
	}
    
    // Display the image in a window
    namedWindow("Example", WINDOW_NORMAL);
	setMouseCallback("Example", onMouse, NULL);
	
    polylines(img, polygonVertices, true, Scalar(0, 255, 0), 2);

    imshow("Example", img);
    
    // Wait for a key press and then exit
    waitKey(0);
    return 0;
}
