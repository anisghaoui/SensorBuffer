#include <iostream>

#include <map>
#include <list>

using namespace std;

int main(int argc, char const *argv[])
{
	map <int,list <float >> S;

	S[4].push_back(6.25);
	for (auto i = S.begin(); i != S.end(); ++i)
	{
		cout <<"this"<<endl;
		for (auto  it = (*i).second.begin(); it != (*i).second.end(); ++it)
		{
			cout << (*it) <<endl;
		}
	}

	if ( S.find(4) != S.end())
	{
		cout << "4 is in map";
		S[4].pop_front();
		cout << S[4].size();
	}
	return 0;
}
