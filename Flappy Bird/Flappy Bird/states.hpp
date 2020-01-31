#pragma once

namespace fp {
	class state {
	public:
		virtual void resume() = 0;
		virtual void pause() = 0;
		virtual void inputHandler()=0;
		virtual void update() = 0;
		virtual void init() = 0;
		virtual void draw(float time) = 0;
		
		
	};
}
