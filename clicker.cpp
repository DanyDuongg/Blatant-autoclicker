
#include "clicker.h"
#include "gui.h"
#include "vars.h"

namespace rng
{
	std::mt19937 gen(std::random_device{}());
	template<typename T>T random_real(T min, T max)
	{
		std::uniform_real_distribution<T> dist(min, max);
		return dist(gen);
	}
}

void PreciseSleep(double millisecond)
{
	auto duration = std::chrono::duration<double, std::milli>(millisecond);
	std::this_thread::sleep_for(duration);
}
void click_mouse(bool is_left)
{
	INPUT input = { 0 };
	input.type = INPUT_MOUSE;
	input.mi.dwFlags = is_left ?
		MOUSEEVENTF_LEFTDOWN :
		MOUSEEVENTF_RIGHTDOWN;
	SendInput(1, &input, sizeof(INPUT));

	input.mi.dwFlags = is_left ?
		MOUSEEVENTF_LEFTUP :
		MOUSEEVENTF_RIGHTUP;
	SendInput(1, &input, sizeof(INPUT));
}

void AutoClicker(float target_cps,bool left_click_check,bool right_click_check, bool is_applied)
{
	while (is_applied)
	{
		float base_delay = 1000.0f / target_cps; //calculate the basedelay in millisecond
		float randomized_delay = base_delay + rng::random_real<float>(-5.0f, 5.0f);
		if (left_click_check)
		{
			click_mouse(true);
		}
		if (right_click_check)
		{
			click_mouse(false);
		}
		PreciseSleep(randomized_delay);
	}
    
}
void start_autoclick()
{
	is_applied = true;
	AutoClicker(saved_cps, saved_is_left, saved_is_right, is_applied);
}
void stop_autoclick()
{
	is_applied = false;
}
