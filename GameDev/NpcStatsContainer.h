class NpcStatsContainer {
	private:
		int hitdmg;
		int health;
		int score;
		float height;
		float width;
	public:
		NpcStatsContainer(int _hitdmg, int _health, int _score, float height, float width);
		~NpcStatsContainer();
		int GetHitDmg();
		int GetHealth();
		int GetScore();
		float GetHeight();
		float GetWidth();
};