#pragma once
#include <iostream>
#include <algorithm>
#include <iterator>
#include <functional>
#include <set>
#include <vector>

class Team{
public:
  void add(Member to_add){ _team.insert(to_add);}
  const std::set<Member,Comp>& team() const { return _team;}
  Team operator- (const Team& t) const {
    Team new_t;
    std::set_intersection(_team.begin(),_team.end(), t._team.begin(),t._team.end(), std::inserter(new_t._team,new_t._team.begin()));    
    return new_t;
  }

  Team operator+ (const Team& t) const {
    Team new_t;
    new_t._team = this->_team;
    new_t._team.insert(t._team.begin(),t._team.end());
    return new_t; 
  }

  void kill(std::function<bool(const Member&)> fun){
    std::vector<Member> remover;
    std::copy(_team.begin(),_team.end() , std::back_inserter(remover)
    );
    remover.erase(std::remove_if(remover.begin(),remover.end(), fun),remover.end());
    _team.clear();
    _team = std::set<Member, Comp> (remover.begin() , remover.end());
  }
private:
  std::set<Member, Comp> _team;
};

std::ostream& operator<<(std::ostream& os, const Team& t){
  std::copy(t.team().begin(),t.team().end(),std::ostream_iterator<Member>(std::cout,"\n"));
  return os;
}