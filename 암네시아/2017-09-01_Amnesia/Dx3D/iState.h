#pragma once

template<typename T>
class iState
{
public:
	virtual void Setup(T character) = 0;
	virtual void Release(T character) = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
};