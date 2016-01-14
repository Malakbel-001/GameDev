#include "Level.h"
#include "PlayState.h"

void Level::ConstructorLevel() {
	entityFactory = nullptr;
	currentPlayer = nullptr;
	player = nullptr;
	vehicle = nullptr;
	timer = nullptr;
	startXpos = 100;
	startYpos = 10;
	actors = new std::vector<Actor*>();
	world = new b2World(b2Vec2(0.0, static_cast<float>(100)));
	contact = new ContactListener();
	world->SetContactListener(contact);
	drawableContainer = new DrawableContainer();
	moveableContainer = new MoveableContainer();
	entities = new std::vector<Entity*>();
	parallaxBackground = nullptr;
}

Level::Level(int _lvlWidth, int _lvlHeight)
	: lvlWidth(_lvlWidth), lvlHeight(_lvlHeight) {
	ConstructorLevel();
}
Level::Level(int _lvlWidth, int _lvlHeight, b2Vec2 vec)
	: lvlWidth(_lvlWidth), lvlHeight(_lvlHeight) {
	ConstructorLevel();
}

void Level::Init(BehaviourFactory* bf, PlayState* play) {
	SetPlayState(play);
	Init(bf);
}

//Always perform these procedures
void Level::Init(BehaviourFactory* bf) {
	SetEntityFactory(bf);
	CreateMap();
	CreateNPCs();
	CreateTimer();
	CreateParallaxBackground(bf);
}

//(Level) EditorState -> PlayState
void Level::SetPlayState(PlayState* play) {
	playState = play;
}

Level::~Level()
{
	if (parallaxBackground)
		delete parallaxBackground;
	delete contact;
	delete world;
	delete drawableContainer;
	if (entityFactory){
		delete entityFactory;
		entityFactory = nullptr;
	}
	if (actors){

		for (auto it = actors->begin(); it != actors->end() && actors; it++)
		{
			if (*it){
				Actor* act = *it;
				//TODO fix this , 
				//delete act;
				
			}
		}
		
		delete actors;
		actors = nullptr;

	}
	for each (Entity* var in *entities)
	{
		if (var){
			delete var;
			var = nullptr;
		}
	}
	delete entities;
	entities = nullptr;
	if (timer)
		delete timer;
	timer = nullptr;
}

std::vector<Actor*>* Level::GetActors(){
	return actors;
}
std::vector<Entity*>* Level::GetEntities(){
	return entities;
}
void Level::Update(float dt, float manipulatorSpeed)
{
	float _x = 1;
	float _y = 10;
	float Ratio = _x / _y;

	bool victory = false;

	//The all important World Step for Box2D
	world->Step((dt / (1000/manipulatorSpeed)), 5, 5);

	
	if (currentPlayer->GetYpos() > lvlHeight || currentPlayer->IsDead())
	{
	//	LevelFactory::SaveLevel(this,"test");
		GameOver();
	}
	else {
		
		//le levelle loopeh
		for (int x = 0; actors->size() > x; x++)
		{
			if (actors->operator[](x)->IsDead()){
				currentPlayer->AddScore(actors->operator[](x)->GetScore());
				if (actors->operator[](x)->GetType() == EntityType::PLANTBOSS || actors->operator[](x)->GetType() == EntityType::SNOWBOSS)
				{
					victory = true;
				}

				if (actors->operator[](x)->GetType() == EntityType::APC)
				{
					if (levelId == 3)
					{
						dynamic_cast<Level3*>(this)->DecrementBossCount();
						if (dynamic_cast<Level3*>(this)->GetBossCount() == 0)
						{
							ExitVehicle();
							GameOver();
						}
					}
				}

				if (actors->operator[](x)->GetType() == EntityType::MECH)
				{
					for (auto weapon : vehicle->GetWeapons()) {
						drawableContainer->Delete(weapon);
						moveableContainer->Delete(weapon);
					}
				}
				//TODO, this stuff should be done depending on the Entity and should be set within the Entity, 
				//or the right function should be called, depending on the Entity.
				//This stuff should be set within some sort of factory, maybe Entity Factory
				if (actors->operator[](x)->GetType() == EntityType::PLANT || actors->operator[](x)->GetType() == EntityType::PINGUIN || actors->operator[](x)->GetType() == EntityType::SNOWMAN){
					float z = actors->operator[](x)->GetBody()->GetPosition().x /Ratio;
					float y = (actors->operator[](x)->GetBody()->GetPosition().y - 4) / Ratio;
					entityFactory->CreateActor(-10, 1, z,y, 7,7, EntityType::HEALTH);
					entityFactory->CreateActor(-10, 1, z, y, 7, 7, EntityType::HEALTH);
					entityFactory->CreateActor(-10, 1, z, y,7,7, EntityType::HEALTH);
					entityFactory->CreateActor(0, 1, z, y, 50,17, EntityType::AMMO);
			
				}

				//for example
				//actors->operator[](x)->GetDrops()
				//Again, drops should be set within the Entity Factory, just as the Score and that stuff is set within the Entity Factory

				currentPlayer->AddScore(actors->operator[](x)->GetScore());

				world->DestroyBody(actors->operator[](x)->GetBody());
				drawableContainer->Delete(actors->operator[](x));
				moveableContainer->Delete(actors->operator[](x));
				delete actors->operator[](x);
				actors->operator[](x) = nullptr;
				actors->erase(actors->begin() + x);
			}

			//this is so the bullets always keep flying (I guess - MJ)
			else if (actors->operator[](x)->GetType() == EntityType::BULLET || actors->operator[](x)->GetType() == EntityType::ACORN || actors->operator[](x)->GetType() == EntityType::CANNONSHOT){
				b2Vec2 vector = actors->operator[](x)->GetDirection();

				vector.x *= manipulatorSpeed;
				vector.y *= manipulatorSpeed;

				actors->operator[](x)->GetBody()->SetLinearVelocity(vector);
			}
		}

		if (victory) {
			Victory();
		}
	}
}

#pragma region Empty functions
void Level::CreateMap() {
	//empty level
}

void Level::CreateNPCs() {
	//empty level
}

void Level::CreateParallaxBackground(BehaviourFactory* bf) {
	//standard background
	parallaxBackground = bf->CreateEmptyParallaxBehaviour();
	parallaxBackground->SetLayer("Resources/backgrounds/game/level1/parallax-forest-back-trees.png", 0, 0.9f, 255);
	parallaxBackground->SetLayer("Resources/backgrounds/game/level1/parallax-forest-lights.png", 0, 0.7f, 120); //cool transparency feature
	parallaxBackground->SetLayer("Resources/backgrounds/game/level1/parallax-forest-middle-trees.png", 0, 1.2f, 255);
	parallaxBackground->SetLayer("Resources/backgrounds/game/level1/parallax-forest-front-trees.png", 0, 1.5f, 255);
}

Player* Level::SetPlayer(Player* _player) {
	//empty level (and empty player)

	return nullptr;
}

Level* Level::CreateLevel() {
	//empty level
	return nullptr;
	//return new Level(lvlWidth, lvlHeight, playState);
}
#pragma endregion
#pragma region Get, Set, & more
Player* Level::SetPlayerPosition(Player* _player, float x, float y) {
	if (!_player->GetBody() != NULL) {
		player = dynamic_cast<Player*>(entityFactory->CreateActor(0, 100, x, y, 15, 35, EntityType::PLAYER));
	}
	else {
		player = entityFactory->CreatePlayer(0, 100, x, y, 15, 35, _player);
		player->SetNumFootContacts(0);
		player->DeletePrevProp();

	}
	return player;
}
Player* Level::GetPlayer() {
	return currentPlayer;
}
DrawableContainer* Level::GetDrawableContainer() {
	return drawableContainer;
}
MoveableContainer* Level::GetMoveableContainer()
{
	return moveableContainer;
}
#pragma endregion Get, Set

void Level::SetEntityFactory(BehaviourFactory* bf) {
	entityFactory = new EntityFactory(*world, actors, entities, bf, this, drawableContainer, moveableContainer);
}
void Level::CreateTimer() {
	timer = new Timer();
}


b2World* Level::GetWorld() {
	return world;
}

ParallaxBackground* Level::GetParallaxBackGround() {
	return parallaxBackground;
}
Timer* Level::GetTimer() {
	return timer;
}
void Level::SetLvlWidth(int _lvlWidth) {
	this->lvlWidth = _lvlWidth;
}
void Level::SetLvlHeight(int _lvlHeight) {
	this->lvlHeight = _lvlHeight;
}
int Level::GetLvlHeight() {
	return this->lvlHeight;
}
EntityFactory* Level::GetEntityFactory() {
	return entityFactory;
}
int Level::GetLvlWidth() {
	return this->lvlWidth;
}
void Level::GameOver() {
	playState->GameOver();
}
void Level::Victory() {
	playState->Victory();
}
void Level::EnterVehicle()
{
	if (currentPlayer->GetType() == EntityType::PLAYER && currentPlayer->GetVehicle())
	{
		vehicle = player->GetVehicle();
		vehicle->AddScore(player->GetScore());
		player->AddScore(-player->GetScore());

		player->SetShouldDraw(false);
		player->GetMoveableBehaviour()->SetDisabled(true);

		vehicle->GetDrawableBehaviour()->SetCamera(player->GetDrawableBehaviour()->GetCamera());

		Weapon* wep = entityFactory->CreateWeapon(0, 0, EntityType::CANNON);
		wep->Pickup(vehicle, b2Vec2(1000, 0));
		vehicle->AddWeapon(wep);
		currentPlayer = vehicle;
		player->GetDrawableBehaviour()->GetCamera()->SetPlayer(vehicle);

		b2Vec2 position;
		position.x = -100;
		position.y = -100;
		player->GetBody()->SetTransform(position, 0);
	}
}

void Level::ExitVehicle()
{
	if (currentPlayer->GetType() == EntityType::MECH)
	{
		player->AddScore(vehicle->GetScore());
		vehicle->AddScore(-vehicle->GetScore());

		b2Vec2 position;
		position.x = vehicle->GetBody()->GetPosition().x + 5;
		position.y = vehicle->GetBody()->GetPosition().y - 5;
		player->GetBody()->SetTransform(position, 0);
		currentPlayer = player;

		currentPlayer->SetShouldDraw(true);
		currentPlayer->GetMoveableBehaviour()->SetDisabled(false);

		vehicle->GetDrawableBehaviour()->GetCamera()->SetPlayer(player);		
	}
}
#pragma endregion Get, Set, & more
