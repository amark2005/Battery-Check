#include <iostream>
#include <cstdio>
#include <string>

double parse_upower(const std::string& output, const std::string& key) {
    size_t pos = output.find(key);
    return std::stod(output.substr(pos + key.size()));
}

int main() {
    char bat[128] = {};
    FILE* p = popen("upower -e | grep BAT", "r");
    fgets(bat, sizeof(bat), p);
    pclose(p);

    std::string bat_path(bat);
    bat_path.erase(bat_path.find_last_not_of(" \n\r") + 1);

    std::string cmd = "upower -i " + bat_path;
    FILE* p2 = popen(cmd.c_str(), "r");
    std::string info;
    char buf[256];
    while (fgets(buf, sizeof(buf), p2)) info += buf;
    pclose(p2);

    double energy_full        = parse_upower(info, "energy-full:         ");
    double energy_full_design = parse_upower(info, "energy-full-design:  ");
    double bat_health         = (energy_full / energy_full_design) * 100;

    std::cout << "\033[32mFull Energy:\033[0m "           << energy_full        << " Wh\n"
              << "\033[32mFull Energy by Design:\033[0m " << energy_full_design << " Wh\n"
              << "\033[32mBattery Health:\033[0m "        << bat_health         << "%\n";
}