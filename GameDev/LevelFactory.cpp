#include "LevelFactory.h"

std::vector<Level*> LevelFactory::levels;
LevelFactory::LevelFactory() { }

LevelFactory::~LevelFactory() {


}
Level* LevelFactory::LoadLevel(PlayState* play, BehaviourFactory* bf, std::string name){
	file<> xmlFile(name.c_str()); // Default template is char
	xml_document<> doc;
	doc.parse<0>(xmlFile.data());
	doc.first_node()->first_attribute();
	xml_node<>* levelnode = doc.first_node();


	LoadedLevel* lvl = new LoadedLevel(2000, 200, b2Vec2(atoi(levelnode->first_attribute("gravity_x")->value()), atoi(levelnode->first_attribute("gravity_y")->value())), play);
	lvl->Init(bf);
	EntityFactory* ent = lvl->GetEntityFactory();

	xml_node<>* currentnode = levelnode->first_node("entities")->first_node();
	while (currentnode != nullptr){
		ent->CreateEntity(
			atoi(currentnode->first_node("xpos")->value()),
			atoi(currentnode->first_node("ypos")->value()),
			atoi(currentnode->first_node("height")->value()),
			atoi(currentnode->first_node("width")->value()),
			static_cast<EntityType>(atoi(currentnode->first_node("type")->value()))
			);


		currentnode = currentnode->next_sibling();

	}


	 currentnode = levelnode->first_node("actors")->first_node();
	while (currentnode != nullptr){
		ent->CreateActor(atoi(currentnode->first_node("xpos")->value()), atoi(currentnode->first_node("ypos")->value())
			, static_cast<EntityType>(atoi(currentnode->first_node("type")->value())));
		

		currentnode = currentnode->next_sibling();

	}

	//Level* lvl = new Level(2000,200,play);

	return lvl;
}
bool LevelFactory::SaveLevel(Level* l,std::string name){
	xml_document<> doc;

	xml_node<> *node = doc.allocate_node(node_element, "level");
	doc.append_node(node);



	char gravity_x[50], gravity_y[50];
	sprintf_s(gravity_x, "%f", l->GetWorld()->GetGravity().x);
	sprintf_s(gravity_y, "%f", l->GetWorld()->GetGravity().y);
	xml_attribute<> *attr = doc.allocate_attribute("gravity_x", gravity_x);

	node->append_attribute(attr);
	attr = doc.allocate_attribute("gravity_y", gravity_y);

	node->append_attribute(attr);
	xml_node<> *actorsnode = doc.allocate_node(node_element, "actors");


	node->append_node(actorsnode);
	//node alle actors
	std::vector<Actor*>* actors = l->GetActors();
	for (std::vector<Actor*>::size_type i = 0; i != actors->size(); i++)
	{

		char _xpos[50], _ypos[50], _type[50];
		sprintf_s(_xpos, "%f", actors->operator[](i)->GetXpos()*10);
		sprintf_s(_ypos, "%f", actors->operator[](i)->GetYpos() * 10);
		sprintf_s(_type, "%i", static_cast<int>(actors->operator[](i)->GetType()));
		
		xml_node<> *actornode = doc.allocate_node(node_element, "actor");
		xml_node<> *xpos = doc.allocate_node(node_element, "xpos", doc.allocate_string(_xpos));
		xml_node<> *ypos = doc.allocate_node(node_element, "ypos", doc.allocate_string(_ypos));
		xml_node<> *type = doc.allocate_node(node_element, "type", doc.allocate_string(_type));
		actornode->append_node(xpos);
		actornode->append_node(ypos);
		actornode->append_node(type);
		actorsnode->append_node(actornode);
	}

	std::vector<Entity*>* entities = l->GetEntities();
	xml_node<> *entitiesnode = doc.allocate_node(node_element, "entities");
	node->append_node(entitiesnode);

	for (std::vector<Entity*>::size_type i = 0; i != entities->size(); i++)
	{

		char _xpos[50], _ypos[50], _type[50], _width[50], _height[50];
		sprintf_s(_xpos, "%f", entities->operator[](i)->GetXpos() * 10);
		sprintf_s(_ypos, "%f", entities->operator[](i)->GetYpos() * 10);
		sprintf_s(_type, "%i", static_cast<int>(entities->operator[](i)->GetType()));
		sprintf_s(_width, "%i", entities->operator[](i)->GetWidth());
		sprintf_s(_height, "%i", entities->operator[](i)->GetHeight());

		xml_node<> *entitynode = doc.allocate_node(node_element, "entity");
		xml_node<> *xpos = doc.allocate_node(node_element, "xpos", doc.allocate_string(_xpos));
		xml_node<> *ypos = doc.allocate_node(node_element, "ypos", doc.allocate_string(_ypos));
		xml_node<> *width = doc.allocate_node(node_element, "width", doc.allocate_string(_width));
		xml_node<> *height = doc.allocate_node(node_element, "height", doc.allocate_string(_height));
		xml_node<> *type = doc.allocate_node(node_element, "type", doc.allocate_string(_type));

	
		entitynode->append_node(xpos);
		entitynode->append_node(ypos);
		entitynode->append_node(width);
		entitynode->append_node(height);
		entitynode->append_node(type);
		entitiesnode->append_node(entitynode);
	}

	std::cout << doc;
	std::cout << attr;


	std::ofstream settings;
	settings.open(name);
	
	if (settings.is_open()) {
		//save all settings (will automatically overwrite previous settings)
		settings << doc;


		settings.close();
	}
	else {
		cout << "Unable to save level" << endl;
		return false;
	}
	return true;

}
void LevelFactory::Init(PlayState* play)
{
	levels = {
		new Level1(2000, 120,play), 
		new Level2(2000,120, play),
		new Level3(2000, 120, play),
		//TODO add , new Level1() , new level2()
	};
}

Level* LevelFactory::GetFirstLevel(PlayState* play)
{
	if (!(levels.size() > 0))
	{
		Init(play);
	}
	return levels[0]->CreateLevel();
}

Level* LevelFactory::GetNextLevel(Level* level, PlayState* play)
{
	if (!(levels.size() > 0))
	{
		Init(play);
	}
	bool foundLevel = false;
	for (size_t i = 0; i < levels.size(); i++)
	{
		if (foundLevel){

			return levels[i];
		}
		if (levels[i]->GetLevelId() == level->GetLevelId()){
			if (i + 1 < levels.size()){
				return levels[i + 1]->CreateLevel();
			}
		}
		//foundLevel = true;
	}

	if (foundLevel)
	{
		// you just finished last level
		// give te first level
		//TODO back to main screen
		return levels[0]->CreateLevel();
	}
	//level was not in levels list get te first level
	return levels[0]->CreateLevel();
}

Level* LevelFactory::GetSpecificLevel(PlayState* play, int lvl){
	if (!(levels.size() > 0))
	{
		Init(play);
	}
	return levels[lvl-1]->CreateLevel();
}

void LevelFactory::DeletePointers(){
	for (auto it = levels.begin(); it != levels.end(); ++it)
	{
		delete *it;
	}
}