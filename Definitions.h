#pragma once
#include <string>

const std::string TITLE = "Amaze";
const int WIDTH = 800;
const int HEIGHT = 600;
const int X_TILES = 40;
const int Y_TILES = 30;
const int TILE_WIDTH = WIDTH / X_TILES;
const int TILE_HEIGHT = HEIGHT / Y_TILES;

const float RAY_LENGTH = 5.0f;
const float CAMERA_SPEED = 5.0f;
const float CAMERA_ANGULAR_SPEED = 4.0f; // deg