class Particle{
	public:
	int X,Y;
	int Index;
	template<class T>void ChangeType();
	Particle();
	virtual void Logic();
	virtual void MoveLogic();
	void SetPos(int x, int y, int** partTable);
	private:
	template<class T>void changeType(Particle* p);
	
	
};