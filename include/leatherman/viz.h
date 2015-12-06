/* \author Benjamin Cohen */

#ifndef _VIZ_
#define _VIZ_

#include <string>
#include <ros/console.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/Vector3.h>
#include <visualization_msgs/MarkerArray.h>
#include <visualization_msgs/Marker.h>
#include <boost/lexical_cast.hpp>
#include <leatherman/utils.h>
#include <moveit_msgs/CollisionObject.h>
#include <shape_msgs/SolidPrimitive.h>

namespace viz {

/* Poses */
visualization_msgs::MarkerArray getPoseMarkerArray(
    const geometry_msgs::Pose& pose,
    const std::string& frame_id,
    const std::string& ns,
    int id = 0,
    bool text = false);

visualization_msgs::MarkerArray getPoseMarkerArray(
    const geometry_msgs::PoseStamped &pose,
    const std::string& ns,
    int id = 0,
    bool text = false);

visualization_msgs::MarkerArray getPosesMarkerArray(
    const std::vector<std::vector<double>>& poses,
    const std::string& frame_id,
    const std::string& ns,
    int id = 0,
    bool text = false);

visualization_msgs::MarkerArray getPosesMarkerArray(
    const std::vector<geometry_msgs::Pose>& poses,
    const std::string& frame_id,
    const std::string& ns,
    int id = 0,
    bool text = false);

/* Spheres */
visualization_msgs::Marker getSphereMarker(
    double x, double y, double z,
    double radius,
    int hue,
    std::string frame_id,
    std::string ns,
    int id = 0);

visualization_msgs::Marker getSpheresMarker(
    const std::vector<std::vector<double> > &pose,
    double radius,
    int hue,
    std::string frame_id,
    std::string ns,
    int id = 0);

visualization_msgs::Marker getSpheresMarker(
    const std::vector<geometry_msgs::Point> &poses,
    double radius,
    int hue,
    std::string frame_id,
    std::string ns,
    int id = 0);

visualization_msgs::MarkerArray getSpheresMarkerArray(
    const std::vector<std::vector<double> > &pose,
    std::vector<double> &radius,
    int hue,
    std::string frame_id,
    std::string ns,
    int id = 0);

visualization_msgs::MarkerArray getSpheresMarkerArray(
    const std::vector<std::vector<double> > &pose,
    const std::vector<int> &hue,
    std::string frame_id,
    std::string ns,
    int id = 0);

/* Line */
visualization_msgs::Marker getLineMarker(
    const std::vector<geometry_msgs::Point>& points,
    double thickness,
    int hue,
    const std::string& frame_id,
    const std::string& ns,
    int id = 0);

/* Text */
visualization_msgs::Marker getTextMarker(
    geometry_msgs::Pose pose,
    std::string text,
    double size,
    int hue,
    std::string frame_id,
    std::string ns,
    int id = 0);

visualization_msgs::Marker getTextMarker(
    geometry_msgs::Pose pose,
    std::string text,
    double size,
    std::vector<double> color,
    std::string frame_id,
    std::string ns,
    int id = 0);

/* Cubes */
visualization_msgs::Marker getCubeMarker(
    geometry_msgs::PoseStamped pose,
    std::vector<double> dim,
    int hue,
    std::string ns,
    int id = 0);

visualization_msgs::Marker getCubeMarker(
    std::vector<double> &cube,
    std::vector<double> &color,
    std::string frame_id,
    std::string ns,
    int id = 0);

visualization_msgs::Marker getCubeMarker(
    geometry_msgs::Pose &pose,
    std::vector<double> &dim,
    std::vector<double> &color,
    std::string frame_id,
    std::string ns,
    int id = 0);

visualization_msgs::Marker getCubesMarker(
    const std::vector<std::vector<double> > &poses,
    double size,
    const std::vector<double> &color,
    std::string frame_id,
    std::string ns,
    int id = 0);

visualization_msgs::MarkerArray getCubesMarkerArray(
    const std::vector<std::vector<double>>& poses,
    double size,
    const std::vector<std::vector<double>>& color,
    const std::string& frame_id,
    const std::string& ns,
    int id = 0);

/* Meshes */
visualization_msgs::Marker getMeshMarker(
    const geometry_msgs::PoseStamped& pose,
    const std::string& mesh_resource,
    int hue,
    std::string ns,
    int id = 0);

visualization_msgs::Marker getMeshMarker(
    const geometry_msgs::PoseStamped &pose,
    const std::vector<geometry_msgs::Point> &vertices,
    const std::vector<int> &triangles,
    int hue,
    bool psychadelic,
    std::string ns,
    int id = 0);

/* Collision Objects */
visualization_msgs::MarkerArray getShapesMarkerArray(
    const std::vector<shape_msgs::SolidPrimitive> &shapes,
    const std::vector<geometry_msgs::Pose> &poses,
    const std::vector<std::vector<double> >&color,
    std::string frame_id,
    std::string ns,
    int id);

visualization_msgs::MarkerArray getCollisionObjectMarkerArray(
    const moveit_msgs::CollisionObject &obj,
    const std::vector<double> &hue,
    std::string ns,
    int id);

/* Removal */
visualization_msgs::MarkerArray getRemoveMarkerArray(
    std::string ns,
    int max_id);

} // namespace viz

#endif
