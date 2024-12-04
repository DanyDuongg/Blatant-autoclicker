#pragma once


#include <chrono>
#include <random>
#include <Windows.h>
#include <thread>



bool GetKeyID(int key);
void PreciseSleep(double milliseconds);
void click_mouse(bool is_left);
void AutoClicker(float target_cps, bool left_click_check, bool right_click_check, bool is_applied);
void start_autoclick();
void stop_autoclick();



