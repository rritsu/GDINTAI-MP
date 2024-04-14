#pragma once

const int GRID_WIDTH = 17;
const int GRID_HEIGHT = 17;

const int BLOCK_SIZE = 16;
const int SCALE_SIZE = 3;

const int SCREEN_WIDTH  = BLOCK_SIZE * SCALE_SIZE * GRID_HEIGHT;
const int SCREEN_HEIGHT = BLOCK_SIZE * SCALE_SIZE * GRID_HEIGHT;

const int GRID_SIZE = BLOCK_SIZE * SCALE_SIZE;

const float FRAME_RATE_LIMIT = 60.0f;
