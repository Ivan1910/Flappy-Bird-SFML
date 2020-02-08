#include "stateMachine.hpp"

namespace fp {

	sRef &stateMachine::currentState() {
		return this->states.top();
	}
	void stateMachine::stateChanges() {
		if (!this->states.empty() && this->isDeleting) {
			this->states.pop();
			if (!this->states.empty()) {
				this->states.top()->resume();
			}
			this->isDeleting = false;
		}
		if (this->isAdding) {
			if(!this->states.empty()){
				if (this->isChanging) {
					this->states.pop();
						}
				else {
					this->states.top()->pause();
					}
			}
		
			this->states.push(std::move(this->newState));
			this->states.top()->init();
			this->isAdding = false;
		}
	}
	void stateMachine::stateDelete(){
		this->isDeleting = true;
	}
	void stateMachine::stateToStack(sRef newState, bool isChanging) {
		this->isChanging = isChanging;
		this->isAdding = true;
		this->newState = std::move(newState);
	}
}