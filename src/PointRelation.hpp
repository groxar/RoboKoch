#pragma once

#include <set>
#include <ostream>
#include <string>
#include <vector>

using namespace ::std;

enum axiom{eq=0,st=1,gt=2,d=3,di=4,o=5,oi=6,m=7,mi=8,s=9,si=10,f=11,fi=12};
struct axiom_compare {
	bool operator() (const axiom lhs,const axiom rhs) const{
		return lhs < rhs; 
	}
};
typedef set<axiom,axiom_compare> axiomSet;

class PointRelation{
	public:
		PointRelation(axiomSet relation = axiomSet({}), int duration = -1);
		~PointRelation();
		PointRelation& operator= (const PointRelation rhs);
		PointRelation operator! ();
		friend PointRelation P(const PointRelation lhs, const PointRelation rhs);
		friend PointRelation operator* (const PointRelation lhs, const PointRelation rhs);
		friend PointRelation operator/ (const PointRelation lhs, const PointRelation rhs);
		friend ostream& operator << (ostream& os, const PointRelation& rhs); 
		int getDuration();
		axiomSet relation;
	private: 
		int duration;
};

PointRelation P(const PointRelation lhs, const PointRelation rhs);
PointRelation operator* (const PointRelation lhs, const PointRelation rhs);
PointRelation operator/ (const PointRelation lhs, const PointRelation rhs);
ostream& operator << (ostream& os, const PointRelation& rhs); 



static axiomSet PTable[13][13] = {
	{axiomSet({eq}),axiomSet({st}),axiomSet({gt}),axiomSet({d}),axiomSet({di}),axiomSet({o}),axiomSet({oi}),axiomSet({m}),axiomSet({mi}),axiomSet({s}),axiomSet({si}),axiomSet({f}),axiomSet({fi})},
	{axiomSet({st}),axiomSet({st}),axiomSet({eq,st,gt,d,di,o,oi,m,mi,s,si,f,fi}),axiomSet({st,o,m,d,s}),axiomSet({st}),axiomSet({st}),axiomSet({st,o,m,d,s}),axiomSet({st}),axiomSet({st,o,m,d,s}),axiomSet({st}),axiomSet({st}),axiomSet({st,o,m,d,s}),axiomSet({st})},
	{axiomSet({gt}),axiomSet({eq,st,gt,d,di,o,oi,m,mi,s,si,f,fi}),axiomSet({gt}),axiomSet({gt,oi,mi,d,f}),axiomSet({gt}),axiomSet({gt,oi,mi,d,f}),axiomSet({gt}),axiomSet({gt,oi,mi,d,f}),axiomSet({gt}),axiomSet({gt,oi,mi,d,f}),axiomSet({gt}),axiomSet({gt}),axiomSet({gt})},
	{axiomSet({d}),axiomSet({st}),axiomSet({gt}),axiomSet({d}),axiomSet({eq,st,gt,d,di,o,oi,m,mi,s,si,f,fi}),axiomSet({st,o,m,d,s}),axiomSet({gt,oi,mi,d,f}),axiomSet({st}),axiomSet({gt}),axiomSet({d}),axiomSet({gt,oi,mi,d,f}),axiomSet({d}),axiomSet({st,o,m,d,s})},
	{axiomSet({di}),axiomSet({st,o,m,di,fi}),axiomSet({st,oi,mi,di,si}),axiomSet({eq,d,di,o,oi,s,si,f,fi}),axiomSet({di}),axiomSet({o,di,fi}),axiomSet({oi,di,si}),axiomSet({o,di,fi}),axiomSet({oi,di,si}),axiomSet({o,di,fi}),axiomSet({di}),axiomSet({oi,di,si}),axiomSet({di})},
	{axiomSet({o}),axiomSet({st}),axiomSet({gt,oi,mi,di,si}),axiomSet({o,d,s}),axiomSet({st,o,m,di,fi}),axiomSet({st,o,m}),axiomSet({eq,d,di,o,oi,s,si,f,fi}),axiomSet({st}),axiomSet({oi,di,si}),axiomSet({o}),axiomSet({di,fi,o}),axiomSet({d,s,o}),axiomSet({st,o,m})},
	{axiomSet({oi}),axiomSet({st,o,m,di,fi}),axiomSet({gt}),axiomSet({oi,d,f}),axiomSet({st,oi,mi,di,si}),axiomSet({eq,d,di,o,oi,s,si,f,fi}),axiomSet({gt,oi,mi}),axiomSet({o,di,fi}),axiomSet({gt}),axiomSet({oi,d,f}),axiomSet({gt,oi,mi}),axiomSet({oi}),axiomSet({oi,di,si})},
	{axiomSet({m}),axiomSet({st}),axiomSet({gt,oi,mi,di,si}),axiomSet({o,d,s}),axiomSet({st}),axiomSet({st}),axiomSet({o,d,s}),axiomSet({st}),axiomSet({eq,f,fi}),axiomSet({m}),axiomSet({m}),axiomSet({d,s,o}),axiomSet({st})},
	{axiomSet({mi}),axiomSet({st,o,m,di,fi}),axiomSet({gt}),axiomSet({oi,d,f}),axiomSet({gt}),axiomSet({oi,d,f}),axiomSet({gt}),axiomSet({eq,s,si}),axiomSet({gt}),axiomSet({d,f,oi}),axiomSet({gt}),axiomSet({mi}),axiomSet({mi})},
	{axiomSet({s}),axiomSet({st}),axiomSet({gt}),axiomSet({d}),axiomSet({st,o,m,di,fi}),axiomSet({st,o,m}),axiomSet({oi,d,f}),axiomSet({st}),axiomSet({mi}),axiomSet({s}),axiomSet({eq,s,si}),axiomSet({d}),axiomSet({st,o,m})},
	{axiomSet({si}),axiomSet({st,o,m,di,fi}),axiomSet({gt}),axiomSet({oi,d,f}),axiomSet({di}),axiomSet({o,di,fi}),axiomSet({oi}),axiomSet({o,di,fi}),axiomSet({mi}),axiomSet({eq,s,si}),axiomSet({si}),axiomSet({oi}),axiomSet({di})},
	{axiomSet({f}),axiomSet({st}),axiomSet({gt}),axiomSet({d}),axiomSet({gt,oi,mi,di,si}),axiomSet({o,d,s}),axiomSet({gt,oi,mi}),axiomSet({m}),axiomSet({gt}),axiomSet({d}),axiomSet({gt,oi,mi}),axiomSet({f}),axiomSet({eq,f,fi})},
	{axiomSet({fi}),axiomSet({st}),axiomSet({gt,oi,mi,di,si}),axiomSet({o,d,s}),axiomSet({di}),axiomSet({o}),axiomSet({oi,di,si}),axiomSet({m}),axiomSet({oi,di,si}),axiomSet({o}),axiomSet({di}),axiomSet({eq,f,fi}),axiomSet({fi})}
};
