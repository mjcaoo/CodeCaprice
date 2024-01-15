/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 *
 * https://leetcode.cn/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (71.52%)
 * Likes:    1238
 * Dislikes: 0
 * Total Accepted:    382.2K
 * Total Submissions: 534.4K
 * Testcase Example:  '3'
 *
 * 给你一个正整数 n ，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 3
 * 输出：[[1,2,3],[8,9,4],[7,6,5]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 1
 * 输出：[[1]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 *
 *
 */
#include <iostream>
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int startx = 0, starty = 0;
        int loop = n / 2;
        int mid = n / 2;
        int count = 1;
        int offset = 1;
        int i, j;
        while (loop--)
        {
            i = startx;
            j = starty;

            for (j = starty; j < n - offset; ++j)
            {
                res[startx][j] = count++;
            }
            for (i = startx; i < n - offset; ++i)
            {
                res[i][j] = count++;
            }
            for (; j > starty; --j)
            {
                res[i][j] = count++;
            }
            for (; i > startx; --i)
            {
                res[i][j] = count++;
            }
            startx++;
            starty++;
            offset++;
        }
        if (n & 1 == 1)
        {
            res[mid][mid] = count;
        }
        return res;
    }
};
// @lc code=end
