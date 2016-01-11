#include "Level.h"
#include "PlayState.h"

Level::Level(int _lvlWidth, int _lvlHeight)
	: lvlWidth(_lvlWidth), lvlHeight(_lvlHeight)
{
	entityFactory = nullptr;
	player = nullptr;
	timer = nullptr;
	startXpos = 100;
	startYpos = 10;
	actors = new std::vector<Actor*>();
	world = new b2World(b2Vec2(0.0, static_cast<float>(50)));
	contact = new ContactListener();
	world->SetContactListener(contact);
	drawableContainer = new DrawableContainer();
	moveableContainer = new MoveableContainer();
	entities = new std::vector<Entity*>();
	parallaxBackground = nullptr;
}
Level::Level(int _lvlWidth, int _lvlHeight, b2Vec2 vec)
	: lvlWidth(_lvlWidth), lvlHeight(_lvlHeight)
{
	entityFactory = nullptr;
	player = nullptr;
	startXpos = 100;
	startYpos = 10;
	actors = new std::vector<Actor*>();
	world = new b2World(vec);
	contact = new ContactListener();
	world->SetContactListener(contact);
	drawableContainer = new DrawableContainer();
	entities = new std::vector<Entity*>();


}


//Always perform these procedures
void Level::Init(BehaviourFactory* bf,PlayState* play) { //TODO get this to work
	playState = play;
	SetEntityFactory(bf);
	CreateMap();
	CreateNPCs();
	CreateTimer();
	CreateParallaxBackground(bf);

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
	}
	for each (Actor* var in *actors)
	{
		if (var){
			delete var;
			var = nullptr;
		}
	}
	delete actors;
	for each (Entity* var in *entities)
	{
		if (var){
			delete var;
			var = nullptr;
		}
	}
	delete entities;
	if (timer)
		delete timer;
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

	//The all important World Step for Box2D
	world->Step((dt / (1000/manipulatorSpeed)), 5, 5);

	if (player->GetYpos() > lvlHeight || player->IsDead())
	{
	//	LevelFactory::SaveLevel(this,"test");
		GameOver();
	}
	else {
		
		//le levelle loopeh
		for (int x = 0; actors->size() > x; x++)
		{
			if (actors->operator[](x)->IsDead()){
				player->AddScore(actors->operator[](x)->GetScore());
				if (actors->operator[](x)->GetType() == EntityType::PLANTBOSS || actors->operator[](x)->GetType() == EntityType::SNOWBOSS)
				{
					Victory();

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

				player->AddScore(actors->operator[](x)->GetScore());

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
	}
}

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
	return player;
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
	if (player->GetVehicle())
	{
		auto vehicle = player->GetVehicle();

		for each (Weapon* var in player->GetWeapons())
		{
			drawableContainer->Delete(var);
			moveableContainer->Delete(var);
		}

		drawableContainer->Delete(player);
		moveableContainer->Delete(player);
		vehicle->SetPassenger(player);
		player->setBody(vehicle->GetBody());
		player = vehicle;

		Weapon* wep = entityFactory->CreateWeapon(0, 0, EntityType::CANNON);
		wep->Pickup(player, b2Vec2(1000, 0));
		player->AddWeapon(wep);
	}
}

void Level::ExitVehicle()
{
	if (player->GetPassenger())
	{
		auto passenger = player->GetPassenger();

		for each (Weapon* var in player->GetWeapons())
		{
			drawableContainer->Delete(var);
			moveableContainer->Delete(var);
		}

		drawableContainer->Delete(player);
		moveableContainer->Delete(player);

		//passenger = SetPlayerPosition(passenger, player->GetBody()->GetWorldCenter().x, player->GetBody()->GetWorldCenter().y + 20);

		player->SetPassenger(nullptr);
		
		player->setBody(passenger->GetBody());
		
		drawableContainer->Add(passenger->GetDrawableBehaviour());
		moveableContainer->Add(passenger->GetMoveableBehaviour());

		Weapon* wep = entityFactory->CreateWeapon(0, 0, EntityType::WEAPON);
		wep->Pickup(player, b2Vec2(100, 0));
		Weapon* shot = entityFactory->CreateWeapon(0, 0, EntityType::SHOTGUN);
		shot->Pickup(player, b2Vec2(100, 0));
		player->AddWeapon(wep);
		player->AddWeapon(shot);
	}
}
#pragma endregion Get, Set, & more
