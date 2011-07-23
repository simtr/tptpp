#ifndef UI_SIMULATIONVIEW_HPP
#define UI_SIMULATIONVIEW_HPP
#include <SFML/Graphics.hpp>
#include <ui/Component.hpp>
#include <Layer.hpp>
#include <Renderer.hpp>
#include <string>

namespace ui
{
	class SimulationView : public Component
	{
	public:
		SimulationView(int x, int y, int width, int height);

		virtual void Tick(float dt);

		virtual void OnMouseUp(int x, int y, unsigned int button);
		virtual void OnMouseDown(int x, int y, unsigned int button);

		virtual void OnMouseEnter(int x, int y, int dx, int dy);
		virtual void OnMouseLeave(int x, int y, int dx, int dy);

		virtual void Draw(void* userdata);

		void AttachRenderer(Renderer *newRenderer);
		void AttachLayer(Layer *simLayer);

	private:
		Renderer *renderer;
		Layer *simulation;
	};
}

#endif
