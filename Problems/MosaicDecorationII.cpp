// Problem link: https://csacademy.com/ieeextreme-practice/task/mosaic2/
// By: Osama Khallouf

#include <iostream>
using namespace std;

/* 
 * W: Width of the wall
 * H: Height of the wall
 * A: Width of the tiles
 * B: Height of the tiles
 * M: Cost of 10 mosaic tiles
 * C: Cost of cutting 1 inch of tiles
 */

int main() {
    long long w, h, a, b, m, c;
    cin >> w >> h >> a >> b >> m >> c;
    
    long long tiles, length;
    long long width, height;
    width = (w+a-1)/a;
    height = (h+b-1)/b;
    tiles = width * height;
    
    length = 0;
    if (w % a != 0)
        length += h;
    if (h % b != 0)
        length += w;
    
    long long answer = (tiles+9)/10 * m + length * c;
    cout << answer;
	return 0;
}

