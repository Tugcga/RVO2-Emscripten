#include <emscripten/bind.h>
#include "RVO.h"
#include "Vector2.h"
#include <math.h>
#include <string>

using namespace emscripten;

std::vector<float> build_float_vector(int size, float value)
{
	return std::vector<float>(size, value);
}

EMSCRIPTEN_BINDINGS(my_module)
{
	class_<RVO::Vector2>("Vector2")
		.constructor<float, float>()
		.function("x", &RVO::Vector2::x)
		.function("y", &RVO::Vector2::y)
		.function("to_string", &RVO::Vector2::toString);

	class_<RVO::RVOSimulator>("RVOSimulator")
		.constructor<float, float, size_t, float, float, float, float>()
		.function("add_agent", &RVO::RVOSimulator::addAgentCoordinates)
		.function("add_agent_ext", &RVO::RVOSimulator::addAgentExt)
		.function("add_obstacle", &RVO::RVOSimulator::addObstacleCoordinates)
		.function("do_step", &RVO::RVOSimulator::doStep)
		.function("get_agent_agent_neighbor", &RVO::RVOSimulator::getAgentAgentNeighbor)
		.function("get_agent_max_neighbors", &RVO::RVOSimulator::getAgentMaxNeighbors)
		.function("get_agent_max_speed", &RVO::RVOSimulator::getAgentMaxSpeed)
		.function("get_agent_neighbor_dist", &RVO::RVOSimulator::getAgentNeighborDist)
		.function("get_agent_num_agent_neighbors", &RVO::RVOSimulator::getAgentNumAgentNeighbors)
		.function("get_agent_num_obstacle_neighbors", &RVO::RVOSimulator::getAgentNumObstacleNeighbors)
		.function("get_agent_obstacle_neighbor", &RVO::RVOSimulator::getAgentObstacleNeighbor)
		.function("get_agent_position", &RVO::RVOSimulator::getAgentPosition)
		.function("get_agent_pref_velocity", &RVO::RVOSimulator::getAgentPrefVelocity)
		.function("get_agent_radius", &RVO::RVOSimulator::getAgentRadius)
		.function("get_agent_time_horizon", &RVO::RVOSimulator::getAgentTimeHorizon)
		.function("get_agent_time_horizon_obst", &RVO::RVOSimulator::getAgentTimeHorizonObst)
		.function("get_agent_velocity", &RVO::RVOSimulator::getAgentVelocity)
		.function("get_global_time", &RVO::RVOSimulator::getGlobalTime)
		.function("get_num_agents", &RVO::RVOSimulator::getNumAgents)
		.function("get_num_obstacle_vertices", &RVO::RVOSimulator::getNumObstacleVertices)
		.function("get_obstacle_vertex", &RVO::RVOSimulator::getObstacleVertex)
		.function("get_next_obstacle_vertex_no", &RVO::RVOSimulator::getNextObstacleVertexNo)
		.function("get_prev_obstacle_vertex_no", &RVO::RVOSimulator::getPrevObstacleVertexNo)
		.function("get_time_step", &RVO::RVOSimulator::getTimeStep)
		.function("process_obstacles", &RVO::RVOSimulator::processObstacles)
		.function("query_visibility", &RVO::RVOSimulator::queryVisibilityCoordinates)
		.function("set_agent_defaults", &RVO::RVOSimulator::setAgentDefaults)
		.function("set_agent_max_neighbors", &RVO::RVOSimulator::setAgentMaxNeighbors)
		.function("set_agent_max_speed", &RVO::RVOSimulator::setAgentMaxSpeed)
		.function("set_agent_neighbor_dist", &RVO::RVOSimulator::setAgentNeighborDist)
		.function("set_agent_position", &RVO::RVOSimulator::setAgentPositionCoordinates)
		.function("set_agent_pref_velocity", &RVO::RVOSimulator::setAgentPrefVelocityCoordinates)
		.function("set_agent_radius", &RVO::RVOSimulator::setAgentRadius)
		.function("set_agent_time_horizon", &RVO::RVOSimulator::setAgentTimeHorizon)
		.function("set_agent_time_horizon_obst", &RVO::RVOSimulator::setAgentTimeHorizonObst)
		.function("set_agent_velocity", &RVO::RVOSimulator::setAgentVelocityCoordinates)
		.function("set_time_step", &RVO::RVOSimulator::setTimeStep);
	function("build_float_vector", &build_float_vector);
	register_vector<float>("vector<float>");
}