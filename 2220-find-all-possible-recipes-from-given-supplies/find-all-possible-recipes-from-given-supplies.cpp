class Solution 
{
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) 
    {
        unordered_set<string> available(supplies.begin(), supplies.end());

        int used_count = 0;
        vector<bool> used(recipes.size(), false);
        vector<string> valid_recipes;

        for (int i = 0; used_count < recipes.size() && i < recipes.size(); ++i)
        {
            bool has_diverged = true;
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
                    used[j] = true,
                    ++used_count,
                    has_diverged = false;
            }
            if (has_diverged)
                break;
        }

        return valid_recipes;
    }
};