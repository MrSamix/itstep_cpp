#include <iostream>
using namespace std;


struct Coordinates
{
    int x;
    int y;
};

struct rectangle
{
    Coordinates upleft;
    Coordinates downright;

    // Task 1
    void printCoordinates()
    {
        cout << "X(" << upleft.x << "," << upleft.y << ")" << "; B(" << downright.x << "," << downright.y << ")" << endl;
    }

    // Task 2
    int Width()
    {
        return downright.x - upleft.x;
    }

    // Task 3
    int Height()
    {
        return upleft.y - downright.y;
    }

    // Task 4
    int Square()
    {
        return Width() * Height();
    }

    // Task 5
    int Perimetr()
    {
        return Width() + Height();
    }

    // Task 6
    void changeWidth(int to_move)
    {
        downright.x += to_move;
    }

    // Task 7
    void changeHeight(int to_move)
    {
        upleft.y += to_move;
    }

    // Task 8
    void changeWidthHeight(int to_move_width, int to_move_height)
    {
        downright.x += to_move_width;
        upleft.y += to_move_height;
    }
    
    // Task 9
    void changeCoordinateX(int to_move_x)
    {
        upleft.x += to_move_x;
        downright.x += to_move_x;
    }

    // Task 10
    void changeCoordinateY(int to_move_y)
    {
        upleft.y += to_move_y;
        downright.y += to_move_y;
    }

    // Task 11
    void changeCoordinateXAndY(int to_move_x, int to_move_y)
    {
        upleft.x += to_move_x;
        upleft.y += to_move_y;
        downright.x += to_move_x;
        downright.y += to_move_y;
    }

    // Task 12
	void isTochkaInRectangle(Coordinates tochka)
	{
		if (tochka.x >= upleft.x && tochka.x <= downright.x && tochka.y >= downright.y && tochka.y <= upleft.y)
		{
			cout << "Tochka in rectangle" << endl;
		}
		else
		{
			cout << "Tochka not in rectangle" << endl;
		}
	}
};

int main()
{
    rectangle rect = { {0,30}, {30,0} };
    // Task 1
    rect.printCoordinates();
    // Task 2
    int width = rect.Width();
    cout << "Width = " << width << endl;
    // Task 3
    int height = rect.Height();
    cout << "Height = " << height << endl;
    // Task 4
    int square = rect.Square();
    cout << "Square = " << square << endl;
    // Task 5
    int perimetr = rect.Perimetr();
    cout << "Perimetr = " << perimetr << endl;
    // Task 6
    rect.changeWidth(-5);
    rect.printCoordinates();
    // Task 7
	rect.changeHeight(-5);
	rect.printCoordinates();
	// Task 8
	rect.changeWidthHeight(-5, -5);
	rect.printCoordinates();
	// Task 9
	rect.changeCoordinateX(-5);
	rect.printCoordinates();
	// Task 10
	rect.changeCoordinateY(-5);
	rect.printCoordinates();
	// Task 11
	rect.changeCoordinateXAndY(-5, -5);
	rect.printCoordinates();
	// Task 12
	Coordinates tochka = { 10, 10 };
	rect.isTochkaInRectangle(tochka);
}