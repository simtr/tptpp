class Particle{
	public:
	int X,Y;
	template<class T>void ChangeType(){}
	Particle(){}
	virtual void Logic()=0;
	virtual void MoveLogic()=0;
	void SetPos(int x, int y, int** partTable){}
	private:
	template<class T>void changeType(Particle* p){}
	
	
};