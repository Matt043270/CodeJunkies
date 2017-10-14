#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <string>
#include "BST.h"
#include "StaticModel.h"
#include "Texture.h"
#include "Entity.h"
#include "EntityKart.h"

class AssetManager
{
public:
		/**
		 * Default Constructor
		 */
	AssetManager();
		/**
		 * Default destructor
		 */
	~AssetManager();

		/**
		* Static function to load all the model data from a specified obj file.
		* @param[in] objFile A string containing the location of the obj file to load.
		* @param[out] model A pointer to a StaticModel object to load the data into.
		*/
	static void LoadObjFile(std::string objFile, StaticModel * model);
		/**
		* Static function to load all the texture data from a specified raw file.
		* @param[in] texFile A string containing the location of the texture file to load.
		* @param[out] texture A pointer to a Texture object to load the data into.
		*/
	static void LoadTexture(std::string texFile, Texture * texture, int width, int height, bool clamp = false);
		/**
		 * Adds a StaticModel pointer to the asset manager.
		 * @param[in] model The pointer to the model
		 */
	void AddModel(StaticModel * model);
		/**
		 * Adds a Texture pointer to the asset manager.
		 * @param[in] texture The pointer to the texture
		 */
	void AddTexture(Texture * texture);
		/**
		 * Adds an Entity pointer to the asset manager.
		 * @param[in] entity The pointer to the entity
		 */
	void AddEntity(Entity * entity);

		/**
		 * Beings the loading of all the assets used by the game.
		 */
	void LoadAllAssets();

		/**
		 * Render all loaded entities onto the screen.
		 */
	void RenderLoadedEntities();

		/**
		 * Unloads all entities, models, and textures from memory.
		 */
	void UnloadAll();
private:
		/**
		 * Callback for the BST, used while rendering each entity.
		 * @param[in] entity The pointer to the entity to render.
		 */
	static void RenderEntityCallback(Entity * entity);
		/**
		 * Callback for the BST, used while unloading the models.
		 * @param[in] model The pointer to the model.
		 */
	static void UnloadModelCallback(StaticModel * model);
		/**
		 * Callback for the BST, used while unloading the textures.
		 * @param[in] texture The pointer to the texture.
		 */
	static void UnloadTextureCallback(Texture * texture);
		/**
		 * Callback for the BST, used while unloading the entities.
		 * @param[in] entity The pointer to the entity.
		 */
	static void UnloadEntityCallback(Entity * entity);
private:
		/**
		 * A BST of all the models
		 */
	BST<StaticModel> m_models;
		/**
		* A BST of all the textures
		*/
	BST<Texture> m_textures;
		/**
		* A BST of all the entites
		*/
	BST<Entity> m_entities;
};

#endif