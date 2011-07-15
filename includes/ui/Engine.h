#ifndef __SYS_ENGINE_H__
#define __SYS_ENGINE_H__

#include <stdio.h>
#include "State.h"

namespace sys
{
	class State;

	class Engine
	{
	public:
		Engine(int width, int height);
		~Engine();

		void onMouseMove(int x, int y);
		void onMouseClick(int x, int y, unsigned int button);
		void onMouseUnclick(int x, int y, unsigned int button);
		void onMouseWheel(int x, int y, int delta);
		void onKeyPress(int key, bool shift, bool ctrl, bool alt);
		void onKeyUnpress(int key, bool shift, bool ctrl, bool alt);
		void onClose();

		void Tick(float dt);
		void Draw();

		inline int GetMouseX() { return mousex_; }
		inline int GetMouseY() { return mousey_; }
		inline int GetWidth() { return width_; }
		inline int GetHeight() { return height_; }

		inline void SetSize(int width, int height);
		
		void SetState(State &state);
	private:
		State* statequeued_;
		State* state_;
		
		int mousex_;
		int mousey_;
		int mousexp_;
		int mouseyp_;
		int width_;
		int height_;
	};

}

#endif // __SYS_ENGINE_H__