#include <iostream>
#include <vector>

// Instead of having a single class(Journal) have the responsibility of
// saving the data, create another class whose sole responsibility is to save data
// to storage.
struct Journal{
    std::string title;
    std::vector<std::string> entries;

    explicit Journal(const std::string& title)
     : title(title)
     {
     }

     void add(const std::string& entry)
     {
         entries.push_back(entry);
     }
}

struct PersistenceManager{
    static void save(const Journal& j, const std::string& filename)
    {
        std::ofstream ofs(filename);
        for(auto& s : j.entries)
            ofs << s << std::endl;
    }
};

