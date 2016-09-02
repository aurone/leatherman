/* \author Benjamin Cohen */

#ifndef _LEATHERMAN_UTILS_
#define _LEATHERMAN_UTILS_

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include <angles/angles.h>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include <geometric_shapes/mesh_operations.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Pose.h>
#include <kdl/chain.hpp>
#include <kdl/frames.hpp>
#include <kdl/tree.hpp>
#include <ros/console.h>
#include <sensor_msgs/JointState.h>
#include <sensor_msgs/MultiDOFJointState.h>
#include <std_msgs/ColorRGBA.h>
#include <tf/LinearMath/Scalar.h>
#include <tf/LinearMath/Transform.h>
#include <tf/LinearMath/Vector3.h>
#include <tf/transform_datatypes.h>
#include <trajectory_msgs/JointTrajectory.h>
#include <urdf/model.h>

namespace leatherman {

void rpyToQuatMsg(double r, double p, double y, geometry_msgs::Quaternion& q);

void setRPY(double roll, double pitch, double yaw, Eigen::Matrix3d& m);
void getRPY(const Eigen::Matrix3d& m, double& roll, double& pitch, double& yaw);
void getRPY(
    const geometry_msgs::Quaternion& qmsg,
    double& roll, double& pitch, double& yaw);
void getRPY(
    const std::vector<std::vector<double> >& Rot,
    double* roll, double* pitch, double* yaw,
    int solution_number);
tf::Quaternion setRPY(
    const tfScalar& roll,
    const tfScalar& pitch,
    const tfScalar& yaw);

double distanceBetween3DLineSegments(
    const Eigen::Vector3d& l1a, const Eigen::Vector3d& l1b,
    const Eigen::Vector3d& l2a, const Eigen::Vector3d& l2b);
void getIntermediatePoints(
    const Eigen::Vector3d& a,
    const Eigen::Vector3d& b,
    double d,
    std::vector<Eigen::Vector3d>& points);
bool getIntermediatePoints(
    trajectory_msgs::JointTrajectoryPoint a,
    trajectory_msgs::JointTrajectoryPoint b,
    int num_points,
    std::vector<trajectory_msgs::JointTrajectoryPoint>& points);

/* Meshes */
shapes::Mesh* createMeshFromBinaryStl(const char *filename);
shapes::Mesh* createMeshFromBinaryStlData(const char *data, unsigned int size);
void getMeshComponents(
    shapes::Mesh* mesh,
    std::vector<int>& triangles,
    std::vector<Eigen::Vector3d>& vertices);
bool getMeshComponentsFromResource(
    const std::string& resource,
    const Eigen::Vector3d& scale,
    std::vector<int>& triangles,
    std::vector<Eigen::Vector3d>& vertices);
void scaleVertices(
    const std::vector<Eigen::Vector3d>& vin,
    double sx, double sy, double sz,
    std::vector<Eigen::Vector3d>& vout);
void scaleVertices(
    const std::vector<geometry_msgs::Point>& vin,
    double sx, double sy, double sz,
    std::vector<geometry_msgs::Point>& vout);
double getColladaFileScale(std::string resource);
bool getLinkMesh(
    std::string urdf,
    std::string name,
    bool collision,
    std::string& mesh_resource,
    geometry_msgs::PoseStamped& pose);

/* Search (string comparisons) */


bool isValidJointState(const sensor_msgs::JointState& state);

bool findJointPosition(
    const sensor_msgs::JointState& state,
    std::string name,
    double& position);

/// \brief Extract a subset of joints from a joint state message.
bool getJointPositions(
    const sensor_msgs::JointState& joint_state,
    const std::vector<std::string>& joint_names,
    std::vector<double>& positions);

/// \brief Extract a subset of joints from a joint state message and report any
///     missing joints.
bool getJointPositions(
    const sensor_msgs::JointState& joint_state,
    const std::vector<std::string>& joint_names,
    std::vector<double>& positions,
    std::vector<std::string>& missing);

void findAndReplaceJointPosition(
    std::string name,
    double position,
    sensor_msgs::JointState& state);

bool getPose(
    const sensor_msgs::MultiDOFJointState& state,
    std::string frame_id,
    std::string child_frame_id,
    geometry_msgs::Pose& pose);

bool getJointIndex(const KDL::Chain& c, std::string name, int& index);

bool getSegmentIndex(const KDL::Chain& c, std::string name, int& index);

bool getSegmentOfJoint(
    const KDL::Tree& tree,
    std::string joint,
    std::string& segment);

bool getChainTip(
    const KDL::Tree& tree,
    const std::vector<std::string>& segments,
    std::string chain_root, std::string& chain_tip);

/* Joint Limits */
bool getJointLimits(
    const urdf::Model* urdf,
    const std::string& root_name,
    const std::string& tip_name,
    std::vector<std::string>& joint_names,
    std::vector<double>& min_limits,
    std::vector<double>& max_limits,
    std::vector<bool>& continuous);

bool getJointLimits(
    const urdf::Model* urdf,
    const std::string& root_name,
    const std::string& tip_name,
    const std::string& joint_name,
    double& min_limit,
    double& max_limit,
    bool& continuous);

/// \brief Convert an (H, S, V) color triplet to (R, G, B) format.
/// \param h The hue in range [0, 360)
/// \param s The saturation in range [0, 1]
/// \param v The value in range [0, 1]
void HSVtoRGB(double* r, double* g, double* b, double h, double s, double v);
void msgRGBToHSV(const std_msgs::ColorRGBA& color, double& h, double& s, double& v);
void msgHSVToRGB(double h, double s, double v, std_msgs::ColorRGBA& color);

/* ROS Logging */
void setLoggerLevel(std::string package, std::string name, std::string level);
void setLoggerLevel(std::string name, std::string level);

} // namespace leatherman

#endif
