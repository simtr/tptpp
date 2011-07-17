class Particle{
	public:
	int X,Y,Type,LayerIndex;
	int Index;
	template<class T>void ChangeType(int);
	virtual void Logic(){};
	virtual void MoveLogic(int**);
	void SetPos(int x, int y, int** partTable);
	private:
	template<class T>void changeType(Particle* p,int);

};
