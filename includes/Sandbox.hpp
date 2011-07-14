#ifndef SANDBOX_HPP
#define SANDBOX_HPP
namespace pt
{
	class Sandbox
	{
	public:
		/* Construct sandbox with the given size (in particles) and the scaling
		factor for low resolution simulation (air, gravity, etc...) */
		Sandbox(int width, int height, int subdivision);
	};
}
#endif