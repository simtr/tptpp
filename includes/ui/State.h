#ifndef __SYS_STATE_H__
#define __SYS_STATE_H__

#include <vector>

#include "Engine.h"
#include "Component.h"

namespace sys
{
	class Engine;
	class Component;
	
	class State
	{
	public:
		State(Engine* engine);
		~State();

		bool AllowExclusiveDrawing; //false will not call draw on objects outside of bounds

		virtual void Initialized();
		virtual void Exit();
		virtual void Tick(float dt);
		virtual void Draw();

		virtual void OnMouseMove(int x, int y, int dx, int dy);
		virtual void OnMouseDown(int x, int y, unsigned int button);
		virtual void OnMouseUp(int x, int y, unsigned int button);
		virtual void OnMouseWheel(int x, int y, int d);
		virtual void OnKeyPress(int key, bool shift, bool ctrl, bool alt);
		virtual void OnKeyUnpress(int key, bool shift, bool ctrl, bool alt);

		inline bool IsFocused(const Component &c);
		inline Engine* GetEngine() { return engine_; }

	protected:
		std::vector<Component*> Components;

	private:
		Engine* engine_;
		Component* focusedComponent_;

	};

}

#endif // __SYS_STATE_H__