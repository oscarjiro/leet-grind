class Solution 
{
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) 
    {
        unordered_set<string> available(supplies.begin(), supplies.end());
        vector<bool> used(recipes.size(), false);
        vector<string> valid_recipes;

        for (int i = 0; i < 100; ++i)
            for (int j = 0; j < recipes.size(); ++j)
            {
                if (used[j])
                    continue;

                int k = 0;
                for (; k < ingredients[j].size(); ++k)
                    if (available.count(ingredients[j][k]) == 0)
                        break;
                
                if (k == ingredients[j].size())
                    valid_recipes.push_back(recipes[j]),
                    available.insert(recipes[j]),
                    used[j] = true;
            }

        return valid_recipes;
    }
};