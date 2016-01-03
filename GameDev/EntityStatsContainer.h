class EntityStatsContainer {
	protected:
		float height;
		float width;

		//virtual void InitializeEntity(float _height, float _width);
	public:
		EntityStatsContainer(float height, float width);
		~EntityStatsContainer();
		virtual float GetHeight();
		virtual float GetWidth();

};