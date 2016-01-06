#include "Level.h"
#include "PlayState.h"

Level::Level(int _lvlWidth, int _lvlHeight, PlayState* ps)
	: lvlWidth(_lvlWidth), lvlHeight(_lvlHeight), playState(ps)
{
	entityFactory = nullptr;
	player = nullptr;
	timer = nullptr;
	startXpos = 100;
	startYpos = 10;
	actors = new std::vector<Actor*>();
	world = new b2World(b2Vec2(0.0, static_cast<float>(1.81)));
	contact = new ContactListener();
	world->SetContactListener(contact);
	drawableContainer = new DrawableContainer();
	moveableContainer = new MoveableContainer();
	entities = new std::vector<Entity*>();
	parallaxBackground = nullptr;
}
Level::Level(int _lvlWidth, int _lvlHeight, b2Vec2 vec,PlayState* ps)
	: lvlWidth(_lvlWidth), lvlHeight(_lvlHeight), playState(ps)
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
void Level::Init(BehaviourFactory* bf) { //TODO get this to work
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
void Level::Update(float dt)
{
	float _x = 1;
	float _y = 10;
	float Ratio = _x / _y;

	world->Step((dt / 200), 5, 5);
	if (player->GetYpos() > lvlHeight || player->IsDead())
	{
	//	LevelFactory::SaveLevel(this,"test");
		GameOver();
	}
	else {
		
		for (int x = 0; actors->size() > x; x++)
		{
			if (actors->operator[](x)->IsDead()){
				player->AddScore(actors->operator[](x)->GetScore());
				if (actors->operator[](x)->GetType() == EntityType::PLANTBOSS || actors->operator[](x)->GetType() == EntityType::SNOWBOSS)
				{
					Victory();

				}

				if (actors->operator[](x)->GetType() == EntityType::PLANT || actors->operator[](x)->GetType() == EntityType::PINGUIN || actors->operator[](x)->GetType() == EntityType::SNOWMAN){
					float z = actors->operator[](x)->GetBody()->GetPosition().x /Ratio;
					float y = (actors->operator[](x)->GetBody()->GetPosition().y - 4) / Ratio;
					entityFactory->CreateActor(-10, 1, z,y, 7,7, EntityType::HEALTH);
					entityFactory->CreateActor(-10, 1, z, y, 7, 7, EntityType::HEALTH);
					entityFactory->CreateActor(-10, 1, z, y,7,7, EntityType::HEALTH);
					entityFactory->CreateActor(0, 1, z, y, 50,17, EntityType::AMMO);
			
				}
				world->DestroyBody(actors->operator[](x)->GetBody());
				drawableContainer->Delete(actors->operator[](x));
				moveableContainer->Delete(actors->operator[](x));
				delete actors->operator[](x);
				actors->operator[](x) = nullptr;
				actors->erase(actors->begin() + x);
			
			}
			else if (actors->operator[](x)->GetType() == EntityType::BULLET){
				actors->operator[](x)->GetBody()->SetLinearVelocity(actors->operator[](x)->GetDirection());
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
#pragma endregion Get, Set, & more
