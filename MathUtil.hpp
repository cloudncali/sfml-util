#ifndef MATH_UTIL_HPP_INCLUDED
#define MATH_UTIL_HPP_INCLUDED

#include <math.h>
#include <SFML/System.hpp>
namespace MathUtil
{
///TILE MAP FUNCTIONS
//Take a take a single index and convert it to an 2d vector based off the width of defined space
template <class T>
sf::Vector2<T> IndexToVector(T a_Index, T a_Width)
{
//Convert to floats for accurrate division. 
sf::Vector2<T> vReturn;
sf::Vector2f vCalc;
float fBounds = a_Width;
float fIndex = float(a_Index);
//Divid by zero check
if (fBounds != 0)
{
vCalc.x = std::fmod(fIndex, fBounds);
vCalc.y = fIndex / fBounds;
}
//return as correct type
vReturn = sf::Vector2<T>((T)vCalc.x,(T)vCalc.y);
return vReturn;
}
//Takes a 2d Vector instead.
template <class T>
sf::Vector2<T> IndexToVector(T a_Index, sf::Vector2<T> a_vBounds)
{
return IndexToVector<T>(a_Index,a_vBounds.x);
}
//Helper functions
inline sf::Vector2i IndexToVector(int a_iIndex, int a_iWidth) { return IndexToVector<int>(a_iIndex, a_iWidth); }
inline sf::Vector2f IndexToVector(float a_fIndex, float a_fWidth) { return IndexToVector<float>(a_fIndex, a_fWidth); }
inline sf::Vector2u IndexToVector(unsigned int a_uIndex, unsigned int a_uWidth) { return IndexToVector<unsigned int>(a_uIndex, a_uWidth); }
 
inline sf::Vector2i IndexToVector(int a_iIndex, sf::Vector2i a_vBounds) {return IndexToVector<int>(a_iIndex, a_vBounds.x);}
inline sf::Vector2f IndexToVector(float a_fIndex, sf::Vector2f a_vBounds){return IndexToVector<float>(a_fIndex, a_vBounds.x);}
inline sf::Vector2u IndexToVector(unsigned int a_uIndex, sf::Vector2u a_vBounds){return IndexToVector<unsigned int>(a_uIndex, a_vBounds.x);}

//Take a 2d vector and translate it to a single valued index based off the max width of the area.
template <class T>
T VectorToIndex(sf::Vector2<T> a_vVector, T a_Width)
{
return a_vVector.x + (a_vVector.y * a_Width);
}
template <class T>
T VectorToIndex(sf::Vector2<T> a_vVector, sf::Vector2<T> a_vBounds)
{
return VectorToIndex<T> (a_vVector, a_vBounds.x);
}

//Helper functions for common types
//Width
inline int VectorToIndex(sf::Vector2i a_vVector, int a_iWidth){return VectorToIndex<int>(a_vVector, a_iWidth);}
inline float VectorToIndex(sf::Vector2f a_vVector, float a_fWidth){return VectorToIndex<float>(a_vVector, a_fWidth);}
inline unsigned int VectorToIndex(sf::Vector2u a_vVector, unsigned int a_uWidth){return VectorToIndex<unsigned int>(a_vVector, a_uWidth);}
//Vectors
inline int VectorToIndex(sf::Vector2i a_vVector, sf::Vector2i a_vBounds) { return VectorToIndex<int>(a_vVector, a_vBounds); }
inline float VectorToIndex(sf::Vector2f a_vVector, sf::Vector2f a_vBounds) { return VectorToIndex<float>(a_vVector, a_vBounds); }
inline unsigned int VectorToIndex(sf::Vector2u a_vVector, sf::Vector2u a_vBounds) { return VectorToIndex<unsigned int>(a_vVector, a_vBounds); }

///MOVEMENT FUNCTIONS
//move a single vector towards a location based off it's speed, keeping it from overshooting it's target.
template <class T>
sf::Vector2<T> MoveToPoint(sf::Vector2<T> a_vCurrentPosition, sf::Vector2<T> a_vTarget, T a_fSpeed)
{
sf::Vector2<T> vReturn(0.f, 0.f);
//Move Xs
T iXDiff = a_vTarget.x - a_vCurrentPosition.x;
if (iXDiff != 0)
{
//if greater than 0 target is to the right.
if (iXDiff > 0)
{
//if the distance is larger than the move speed, move full speed
if (iXDiff > a_fSpeed)
vReturn.x = a_fSpeed;
//else we set to target location. this prevents overshooting
else
vReturn.x = iXDiff;
}
//if less than 0 target is to the left.
else if (iXDiff < 0)
{
//if the distance is less than the negitive move speed, move full speed
if (iXDiff < -a_fSpeed)
vReturn.x = -a_fSpeed;
//else we set to target location. this prevents overshooting
else
vReturn.x = iXDiff;
}
}
//Move Y
int iYDiff = a_vTarget.y - a_vCurrentPosition.y;
if (iYDiff != 0)
{
//if greater than 0 target is below.
if (iYDiff > 0)
{
//if the distance is larger than the move speed, move full speed
if (iYDiff > a_fSpeed)
vReturn.y = a_fSpeed;
//else we set to target location. this prevents overshooting
else
vReturn.y = iYDiff;
}
//if less than 0 target is above.
else if (iYDiff < 0)
{
//if the distance is less than the negitive move speed, move full speed
if (iYDiff < -a_fSpeed)
vReturn.y = -a_fSpeed;
//else we set to target location. this prevents overshooting
else
vReturn.y = iYDiff;
}
}
return vReturn;
}

//Helper functions for common types
inline sf::Vector2i MoveToPoint(sf::Vector2i a_vCurrentPosition, sf::Vector2i a_vTarget, int a_iSpeed){return MoveToPoint<int>(a_vCurrentPosition, a_vTarget, a_iSpeed);}
inline sf::Vector2f MoveToPoint(sf::Vector2f a_vCurrentPosition, sf::Vector2f a_vTarget, float a_fSpeed){return MoveToPoint<float>(a_vCurrentPosition, a_vTarget, a_fSpeed);}
inline sf::Vector2u MoveToPoint(sf::Vector2u a_vCurrentPosition, sf::Vector2u a_vTarget, unsigned int a_uSpeed) { return MoveToPoint<unsigned int>(a_vCurrentPosition, a_vTarget, a_uSpeed); }

//VECTOR MATH FUNCTIONS
//Add two 2D sfml vectors togeather
	template <class T>
	sf::Vector2<T> vectorAdd(sf::Vector2<T> a_VectorA, sf::Vector2<T> a_VectorB)
	{
		return sf::Vector2<T>(a_VectorA.x + a_VectorB.x, a_VectorA.y + a_VectorB.y);
	}

//Helper functions for common types
inline sf::Vector2i vectorAdd(sf::Vector2i a_VectorA, sf::Vector2i a_VectorB) {return vectorAdd<int>(a_VectorA,a_VectorB);}
inline sf::Vector2f vectorAdd(sf::Vector2f a_VectorA, sf::Vector2f a_VectorB) {return vectorAdd<float>(a_VectorA,a_VectorB);}
inline sf::Vector2u vectorAdd(sf::Vector2u a_VectorA, sf::Vector2u a_VectorB) {return vectorAdd<unsigned int>(a_VectorA,a_VectorB);}


//Add a 2D SFML vector by a scalar
template <class T>
sf::Vector2<T> vectorAdd(sf::Vector2<T> a_VectorA, T a_Scalar)
{
return vectorAdd<T>(a_VectorA, sf::Vector2<T>(a_Scalar, a_Scalar));
}
//Helper functions for common types
inline sf::Vector2i vectorAdd(sf::Vector2i a_VectorA, int a_iScalar) { return vectorAdd<int>(a_VectorA, a_iScalar); }
inline sf::Vector2f vectorAdd(sf::Vector2f a_VectorA, float a_fScalar) { return vectorAdd<float>(a_VectorA, a_fScalar); }
inline sf::Vector2u vectorAdd(sf::Vector2u a_VectorA, unsigned int a_uScalar) { return vectorAdd<unsigned int>(a_VectorA, a_uScalar); }

//Subtract two 2D sfml vectors
template <class T>
	sf::Vector2<T> vectorSubtract(sf::Vector2<T> a_VectorA, sf::Vector2<T> a_VectorB)
	{
		return sf::Vector2<T>(a_VectorA.x - a_VectorB.x, a_VectorA.y - a_VectorB.y);
	}

//Helper functions for common types
inline sf::Vector2i vectorSubtract(sf::Vector2i a_VectorA, sf::Vector2i a_VectorB) { return vectorSubtract<int>(a_VectorA, a_VectorB); }
inline sf::Vector2f vectorSubtract(sf::Vector2f a_VectorA, sf::Vector2f a_VectorB) { return vectorSubtract<float>(a_VectorA, a_VectorB); }
inline sf::Vector2u vectorSubtract(sf::Vector2u a_VectorA, sf::Vector2u a_VectorB) { return vectorSubtract<unsigned int>(a_VectorA, a_VectorB); }

//Substract a 2D SFML vector by a scalar
template <class T>
sf::Vector2<T> vectorSubtract(sf::Vector2<T> a_VectorA, T a_Scalar)
{
return vectorSubtract<T>(a_VectorA, sf::Vector2<T>(a_Scalar, a_Scalar));
}

//Helper functions for common types
inline sf::Vector2i vectorSubtract(sf::Vector2i a_VectorA, int a_iScalar) { return vectorSubtract<int>(a_VectorA, a_iScalar); }
inline sf::Vector2f vectorSubtract(sf::Vector2f a_VectorA, float a_fScalar) { return vectorSubtract<float>(a_VectorA, a_fScalar); }
inline sf::Vector2u vectorSubtract(sf::Vector2u a_VectorA, unsigned int a_uScalar) { return vectorSubtract<unsigned int>(a_VectorA, a_uScalar); }


//Multiply two 2D sfml vectors togeather
	template <class T>
	sf::Vector2<T> vectorMultiply(sf::Vector2<T> a_VectorA, sf::Vector2<T> a_VectorB)
	{
		return sf::Vector2<T>(a_VectorA.x * a_VectorB.x, a_VectorA.y * a_VectorB.y);
	}

//Helper functions for common types
inline sf::Vector2i vectorMultiply(sf::Vector2i a_VectorA, sf::Vector2i a_VectorB) { return vectorMultiply<int>(a_VectorA, a_VectorB); }
inline sf::Vector2f vectorMultiply(sf::Vector2f a_VectorA, sf::Vector2f a_VectorB) { return vectorMultiply<float>(a_VectorA, a_VectorB); }
inline sf::Vector2u vectorMultiply(sf::Vector2u a_VectorA, sf::Vector2u a_VectorB) { return vectorMultiply<unsigned int>(a_VectorA, a_VectorB); }


//Multiply a 2D SFML vector by a scalar
template <class T>
sf::Vector2<T> vectorMultiply(sf::Vector2<T> a_VectorA, T a_Scalar)
{
return vectorMultiply<T>(a_VectorA, sf::Vector2<T>(a_Scalar, a_Scalar));
}

//Helper functions for common types
inline sf::Vector2i vectorMultiply(sf::Vector2i a_VectorA, int a_iScalar) { return vectorMultiply<int>(a_VectorA, a_iScalar); }
inline sf::Vector2f vectorMultiply(sf::Vector2f a_VectorA, float a_fScalar) { return vectorMultiply<float>(a_VectorA, a_fScalar); }
inline sf::Vector2u vectorMultiply(sf::Vector2u a_VectorA, unsigned int a_uScalar) { return vectorMultiply<unsigned int>(a_VectorA, a_uScalar); }


//Divide two 2D sfml vectors
	template <class T>
	sf::Vector2<T> vectorDivide(sf::Vector2<T> a_VectorA, sf::Vector2<T> a_VectorB)
	{
		sf::Vector2<T> vReturn;
		//Prevent divide by zero.
		if(a_VectorB.x==0 || a_VectorB.y==0)
			vReturn = sf::Vector2<T>(0,0);
		else
			vReturn = sf::Vector2<T>(a_VectorA.x / a_VectorB.x, a_VectorA.y / a_VectorB.y);
		return vReturn;
	}

//Helper functions for common types
inline sf::Vector2i vectorDivide(sf::Vector2i a_VectorA, sf::Vector2i a_VectorB) { return vectorDivide<int>(a_VectorA, a_VectorB); }
inline sf::Vector2f vectorDivide(sf::Vector2f a_VectorA, sf::Vector2f a_VectorB) { return vectorDivide<float>(a_VectorA, a_VectorB); }
inline sf::Vector2u vectorDivide(sf::Vector2u a_VectorA, sf::Vector2u a_VectorB) { return vectorDivide<unsigned int>(a_VectorA, a_VectorB); }

//Divide a 2D SFML vector by a scalar
template <class T>
sf::Vector2<T> vectorDivide(sf::Vector2<T> a_VectorA, T a_Scalar)
{
return vectorDivide<T>(a_VectorA,sf::Vector2<T>(a_Scalar, a_Scalar));
}

//Helper functions for common types
inline sf::Vector2i vectorDivide(sf::Vector2i a_VectorA, int a_iScalar) { return vectorDivide<int>(a_VectorA, a_iScalar); }
inline sf::Vector2f vectorDivide(sf::Vector2f a_VectorA, float a_fScalar) { return vectorDivide<float>(a_VectorA, a_fScalar); }
inline sf::Vector2u vectorDivide(sf::Vector2u a_VectorA, unsigned int a_uScalar) { return vectorDivide<unsigned int>(a_VectorA, a_uScalar); }

//Cross Product of two vectors
	template <class T>
	sf::Vector2<T> vectorCross(sf::Vector2<T> a_VectorA, sf::Vector2<T> a_VectorB)
	{
		return sf::Vector2<T>(a_VectorA.x * a_VectorB.y, a_VectorA.y * a_VectorB.x);
	}

//Helper functions for common types
inline sf::Vector2i vectorCross(sf::Vector2i a_VectorA, sf::Vector2i a_VectorB) { return vectorCross<int>(a_VectorA, a_VectorB); }
inline sf::Vector2f vectorCross(sf::Vector2f a_VectorA, sf::Vector2f a_VectorB) { return vectorCross<float>(a_VectorA, a_VectorB); }
inline sf::Vector2u vectorCross(sf::Vector2u a_VectorA, sf::Vector2u a_VectorB) { return vectorCross<unsigned int>(a_VectorA, a_VectorB); }
}

#endif
