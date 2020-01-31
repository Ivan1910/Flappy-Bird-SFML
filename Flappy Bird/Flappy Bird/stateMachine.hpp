#pragma once

#include<stack>
#include<memory>

#include "states.hpp"

namespace fp {
	typedef std::unique_ptr<state> sRef;

	class stateMachine {
	public:
		stateMachine() {}
		~stateMachine(){}
		void stateToStack(sRef newState, bool isChanging = true);
		void stateDelete();
		void stateChanges();
		
		sRef &currentState();

	private:
		bool isDeleting;
		bool isChanging;
		bool isAdding;
		
		std::stack<sRef> states;
		sRef newState;
		
	};
}
