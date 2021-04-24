
#ifndef _PIECE_H
#define _PIECE_H
#include<string>
#include<vector>
#include<iostream>
#pragma comment(lib, "gdiplus.lib")
using namespace std;

//Class for player movement

class Piece {
private:
	Piece();
	~Piece();
	Piece(string nm, int pl, int iny, int inx, int mm);
