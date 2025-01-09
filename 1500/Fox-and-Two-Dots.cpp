#include <iostream>
#include <vector>
#include <string>

// fox and two dots
bool dfs(std::vector<std::string>& matrix, std::vector<std::vector<bool>>& visited, long long x, long long y, long long& xstart, long long& ystart, long long curLength, bool& cycle)
{
	if(cycle)
	{
		return true;
	}
	visited[x][y] = true;
	if(x == xstart && y == ystart && curLength >= 3)
	{
		cycle = true;
		return true;
	}
	bool flag1 = false;
	bool flag2 = false;
	bool flag3 = false;
	bool flag4 = false;
	if(x-1 >= 0 && matrix[x-1][y] == matrix[xstart][ystart])
	{
		if(visited[x-1][y] && x-1 == xstart && y == ystart && curLength >= 3)
		{
			cycle = true;
			return true;
		}
		if(!visited[x-1][y])
		{
			flag2 = dfs(matrix, visited, x-1, y, xstart, ystart, curLength+1, cycle);
		}
	}
	if(y-1 >= 0 && matrix[x][y-1] == matrix[xstart][ystart])
	{	
		if(visited[x][y-1] && x == xstart && y-1 == ystart && curLength >= 3)
		{
			cycle = true;
			return true;
		}
		if(!visited[x][y-1])
		{
			flag4 = dfs(matrix, visited, x, y-1, xstart, ystart, curLength+1, cycle);
		}
	}
	if(x+1 < matrix.size() && matrix[x+1][y] == matrix[xstart][ystart])
	{
		if(visited[x+1][y] && x+1 == xstart && y == ystart && curLength >= 3)
		{
			cycle = true;
			return true;
		}
		if(!visited[x+1][y])
		{
			flag1 = dfs(matrix, visited, x+1, y, xstart, ystart, curLength+1, cycle);
		}
	}
	if(y+1 < matrix[0].length() && matrix[x][y+1] == matrix[xstart][ystart])
	{
		if(visited[x][y+1] && x == xstart && y+1 == ystart && curLength >= 3)
		{
			cycle = true;
			return true;
		}
		if(!visited[x][y+1])
		{	
			flag3 = dfs(matrix, visited, x, y+1, xstart, ystart, curLength+1, cycle);
		}
	}
	visited[x][y] = false;
	return flag1 || flag2 || flag3 || flag4;
}

int main()
{
	long long n, m;
	std::cin >> n >> m;
	std::vector<std::string> matrix(n);
	for(int i = 0; i < n; i++)
	{
		std::cin >> matrix[i];
	}
	std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
	bool flag = false;
	for(long long i = 0; i < n; i++)
	{
		for(long long j = 0; j < m; j++)
		{
			if(!visited[i][j])
			{
				if(dfs(matrix, visited, i, j, i, j, 0, flag))
				{
					flag = true;
					i = n;
					break;
				}
			}
		}
	}
	if(flag)
	{
		std::cout << "Yes";
	}
	else
	{
		std::cout << "No";
	}
	return 0;
}
