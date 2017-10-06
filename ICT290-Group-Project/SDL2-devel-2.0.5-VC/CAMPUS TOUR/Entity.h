#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include "StaticModel.h"

	/**
	 * A structure that represents a models offset to the position of the entity.
	 */
struct Offset
{
	float x, y, z;
	Offset() {}
	Offset(float newX, float newY, float newZ)
	{
		x = newX;
		y = newY;
		z = newZ;
	}
};

	/**
	 * A structure that represents a StaticModel and its Offset.
	 */
struct OffsetModel
{
	Offset os;
	StaticModel * model;
	OffsetModel()
	{
		model = nullptr;
	}
	OffsetModel(Offset newOs, StaticModel * newModel)
	{
		os = newOs;
		model = newModel;
	}
};

class Entity
{
public:
		/**
		 * Default constructor
		 */
	Entity();
		/**
		 * Default destructor
		 */
	~Entity();

		/**
		 * Adds a model to the Entity.
		 * @param[in] model A pointer to the model thats being added.
		 * @param[in] offX The x offset.
		 * @param[in] offY The y offset.
		 * @param[in] offZ The z offset.
		 */
	void AddModel(StaticModel * model, float offX, float offY, float offZ);
		/**
		 * Translates the entity.
		 * @param[in] tx How far along the x Axis the entity is being translated.
		 * @param[in] ty How far along the y Axis the entity is being translated.
		 * @param[in] tz How far along the z Axis the entity is being translated.
		 */
	void Translate(float tx, float ty, float tz);
		/**
		 * Scales the entity.
		 * @param[in] newScale How big the entity is.
		 */
	void Scale(float newScale);
		/**
		 * Rotate the entity.
		 * @param[in] rx How far along the x Axis the entity is being rotated.
		 * @param[in] ry How far along the y Axis the entity is being rotated.
		 * @param[in] rz How far along the z Axis the entity is being rotated.
		 */
	void Rotate(float rx, float ry, float rz);

		/**
		 * Sets the entity to an absolute position.
		 * @param[in] newX The x position to set the entity.
		 * @param[in] newY The y position to set the entity.
		 * @param[in] newZ The z position to set the entity.
		 */
	void SetPosition(float newX, float newY, float newZ);
		/**
		 * Sets the entity to an absolute rotation.
		 * @param[in] newX The x rotation to set the entity.
		 * @param[in] newY The y rotation to set the entity.
		 * @param[in] newZ The z rotation to set the entity.
		*/
	void SetRotation(float newX, float newY, float newZ);
private:

private:
		/**
		 * The x, y, and z positions of the entity.
		 */
	float x, y, z;
		/**
		 * The scale of the entity.
		 */
	float scale;
		/**
		 * The x, y, and z rotations of the entity.
		 */
	float xr, yr, zr;
		/**
		 * A vector containing all the models to be rendered, and their offsets from the entity.
		 */
	std::vector<OffsetModel*> m_models;

};

#endif