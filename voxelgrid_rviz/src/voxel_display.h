#ifndef VOXEL_DISPLAY_H
#define VOXEL_DISPLAY_H

#include <rviz/message_filter_display.h>
#include <rviz/properties/color_property.h>
#include <rviz/properties/float_property.h>
#include <rviz/properties/int_property.h>
#include <voxelgrid_msgs/VoxelGridFloat32MultiarrayStamped.h>
#include <voxelgrid_msgs/VoxelGridInt16MultiarrayStamped.h>
#include <boost/circular_buffer.hpp>

#include "voxel_visual.h"

namespace voxelgrid_rviz {

class Float32VoxelGridDisplay : public rviz::MessageFilterDisplay<voxelgrid_msgs::VoxelGridFloat32MultiarrayStamped> {
  Q_OBJECT
 public:
  // Constructor.  pluginlib::ClassLoader creates instances by calling
  // the default constructor, so make sure you have one.
  Float32VoxelGridDisplay();
  ~Float32VoxelGridDisplay() override;

  // Overrides of protected virtual functions from Display.  As much
  // as possible, when Displays are not enabled, they should not be
  // subscribed to incoming data and should not show anything in the
  // 3D view.  These functions are where these connections are made
  // and broken.
 protected:
  void onInitialize() override;

  // A helper to clear this display back to the initial state.
  void reset() override;

  // These Qt slots get connected to signals indicating changes in the user-editable properties.
 private Q_SLOTS:
  virtual void updateColorAndAlpha();

 private:
  // Function to handle an incoming ROS message.
  void processMessage(const voxelgrid_msgs::VoxelGridFloat32MultiarrayStamped::ConstPtr& msg) override;

  // Storage for the list of visuals.  It is a circular buffer where
  // data gets popped from the front (oldest) and pushed to the back (newest)
  boost::shared_ptr<Float32VoxelGridVisual> visual_;

  // User-editable property variables.
  rviz::BoolProperty* hide_property_;
  rviz::ColorProperty* color_property_;
  rviz::FloatProperty* alpha_property_;
  rviz::BoolProperty* binary_display_property_;
  rviz::FloatProperty* cutoff_property_;
};

class Int16VoxelGridDisplay : public rviz::MessageFilterDisplay<voxelgrid_msgs::VoxelGridInt16MultiarrayStamped> {
 Q_OBJECT
 public:
  // Constructor.  pluginlib::ClassLoader creates instances by calling
  // the default constructor, so make sure you have one.
  Int16VoxelGridDisplay();
  ~Int16VoxelGridDisplay() override;

  // Overrides of protected virtual functions from Display.  As much
  // as possible, when Displays are not enabled, they should not be
  // subscribed to incoming data and should not show anything in the
  // 3D view.  These functions are where these connections are made
  // and broken.
 protected:
  void onInitialize() override;

  // A helper to clear this display back to the initial state.
  void reset() override;

  // These Qt slots get connected to signals indicating changes in the user-editable properties.
 private Q_SLOTS:
  virtual void updateColorAndAlpha();

 private:
  // Function to handle an incoming ROS message.
  void processMessage(const voxelgrid_msgs::VoxelGridInt16MultiarrayStamped::ConstPtr& msg) override;

  // Storage for the list of visuals.  It is a circular buffer where
  // data gets popped from the front (oldest) and pushed to the back (newest)
  boost::shared_ptr<Int16VoxelGridVisual> visual_;

  // User-editable property variables.
  rviz::BoolProperty* hide_property_;
  rviz::ColorProperty* color_property_;
  rviz::FloatProperty* alpha_property_;
  rviz::BoolProperty* binary_display_property_;
  rviz::FloatProperty* cutoff_property_;
};

}  // end namespace voxelgrid_rviz

#endif  // VOXEL_DISPLAY_H
