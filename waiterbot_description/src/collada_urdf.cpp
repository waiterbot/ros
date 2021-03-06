#include <collada_urdf/collada_urdf.h>

boost::shared_ptr<DAE> dom;
if (!collada_urdf::colladaFromUrdfFile("waiterbot.urdf", dom)) {
    ROS_ERROR("Failed to construct COLLADA DOM");
    return false;
}
collada_urdf::colladaToFile(dom, "waiterbot.dae");
