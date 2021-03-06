#include "defaults.h"
#include <vector>
#include <cstring>
#include <cassert>
#include <algorithm>


namespace monodepth{
namespace config{

void SetCFGFromFile(const std::string file_path){
  
  cfg = new YAML::Node(YAML::LoadFile(file_path));
  
  SetNode((*cfg)["MODEL"], YAML::Node());
  SetNode((*cfg)["MODEL"]["RPN_ONLY"], false);
  SetNode((*cfg)["MODEL"]["MASK_ON"], false);
  SetNode((*cfg)["MODEL"]["RETINANET_ON"], false);
  SetNode((*cfg)["MODEL"]["KEYPOINT_ON"], false);
  SetNode((*cfg)["MODEL"]["DEVICE"], "cuda");
  SetNode((*cfg)["MODEL"]["META_ARCHITECTURE"], "SelfDepthModel");
  SetNode((*cfg)["MODEL"]["CLS_AGNOSTIC_BBOX_REG"], false);
  SetNode((*cfg)["MODEL"]["WEIGHT"], "");
  //input
  SetNode((*cfg)["INPUT"], YAML::Node());
  SetNode((*cfg)["INPUT"]["MIN_SIZE_TRAIN"], 800);
  SetNode((*cfg)["INPUT"]["MAX_SIZE_TRAIN"], 1333);
  SetNode((*cfg)["INPUT"]["MIN_SIZE_TEST"], 800);
  SetNode((*cfg)["INPUT"]["MAX_SIZE_TEST"], 1333);
  SetNode((*cfg)["INPUT"]["PIXEL_MEAN"], "(102.9801, 115.9465, 122.7717)");
  SetNode((*cfg)["INPUT"]["PIXEL_STD"], "(1., 1., 1.)");
  SetNode((*cfg)["INPUT"]["TO_BGR255"], true);
  SetNode((*cfg)["INPUT"]["VERTICAL_FLIP_PROB_TRAIN"], 0.0);

  SetNode((*cfg)["INPUT"]["RIGHTNESS"], 0.0);
  SetNode((*cfg)["INPUT"]["CONTRAST"], 0.0);
  SetNode((*cfg)["INPUT"]["SATURATION"], 0.0);
  SetNode((*cfg)["INPUT"]["HUE"], 0.0);

  //DATASET
  SetNode((*cfg)["DATASETS"], YAML::Node());
  SetNode((*cfg)["DATASETS"]["TRAIN"], "cityscapes_fine");
  SetNode((*cfg)["DATASETS"]["TEST"], "city");
  SetNode((*cfg)["DATASETS"]["IMG_HEIGHT"], "192");
  SetNode((*cfg)["DATASETS"]["IMG_WIDTH"], "640");
  SetNode((*cfg)["DATASETS"]["IMG_EXT"], ".png");
  //DATALOADER
  SetNode((*cfg)["DATALOADER"], YAML::Node());
  SetNode((*cfg)["DATALOADER"]["NUM_WORKERS"], 4);
  SetNode((*cfg)["DATALOADER"]["SIZE_DIVISIBILITY"], 0);
  SetNode((*cfg)["DATALOADER"]["ASPECT_RATIO_GROUPING"], true);
  
  //BACKBONE
  SetNode((*cfg)["MODEL"]["BACKBONE"], YAML::Node());
  SetNode((*cfg)["MODEL"]["BACKBONE"]["CONV_BODY"], "R-50-C4");
  SetNode((*cfg)["MODEL"]["BACKBONE"]["FREEZE_CONV_BODY_AT"], 2);
  //SetNode((*cfg)["MODEL"]["BACKBONE"]["USE_GN"], false);
  
 
  

  //Group Norm
  SetNode((*cfg)["MODEL"]["GROUP_NORM"], YAML::Node());
  SetNode((*cfg)["MODEL"]["GROUP_NORM"]["DIM_PER_GP"], -1);
  SetNode((*cfg)["MODEL"]["GROUP_NORM"]["NUM_GROUPS"], 32);
  SetNode((*cfg)["MODEL"]["GROUP_NORM"]["EPSILON"], 1e-5);
  
  //RESNET
  SetNode((*cfg)["MODEL"]["RESNETS"], YAML::Node());
  SetNode((*cfg)["MODEL"]["RESNETS"]["NUM_GROUPS"], 1);
  SetNode((*cfg)["MODEL"]["RESNETS"]["WIDTH_PER_GROUP"], 64);
  SetNode((*cfg)["MODEL"]["RESNETS"]["STRIDE_IN_1X1"], true);
  SetNode((*cfg)["MODEL"]["RESNETS"]["TRANS_FUNC"], "BottleneckWithFixedBatchNorm");
  SetNode((*cfg)["MODEL"]["RESNETS"]["STEM_FUNC"], "StemWithFixedBatchNorm");
  SetNode((*cfg)["MODEL"]["RESNETS"]["RES5_DILATION"], 1);
  SetNode((*cfg)["MODEL"]["RESNETS"]["BACKBONE_OUT_CHANNELS"], 1024);
  SetNode((*cfg)["MODEL"]["RESNETS"]["RES2_OUT_CHANNELS"], 256);
  SetNode((*cfg)["MODEL"]["RESNETS"]["STEM_OUT_CHANNELS"], 64);
  // std::vector<bool> vec{false, false, false, false};
  // SetNode((*cfg)["MODEL"]["RESNET"]["STAGE_WITH_DCN"], vec);
  // SetNode((*cfg)["MODEL"]["RESNET"]["DEFORMABLE_GROUPS"], 1);

  SetNode((*cfg)["MODEL"]["VOVNET"], YAML::Node());
  SetNode((*cfg)["MODEL"]["VOVNET"]["PRETRAINED"], "");
  // SetNode((*cfg)["MODEL"]["VOVNET"]["USE_GN"], false);
  SetNode((*cfg)["MODEL"]["VOVNET"]["OUT_CHANNELS"], 256);
  SetNode((*cfg)["MODEL"]["VOVNET"]["BACKBONE_OUT_CHANNELS"], 256);


  //depth
  SetNode((*cfg)["MODEL"]["DEPTH"], YAML::Node());
  SetNode((*cfg)["MODEL"]["DEPTH"]["NUM_CH_ENC"], (64, 128, 256, 512, 512));
  SetNode((*cfg)["MODEL"]["DEPTH"]["NUM_CH_DEC"], (64, 128, 256, 512, 512));
  SetNode((*cfg)["MODEL"]["DEPTH"]["USE_SKIPS"], true);
  SetNode((*cfg)["MODEL"]["DEPTH"]["NUM_FRAMES"], 3);
  SetNode((*cfg)["MODEL"]["DEPTH"]["OUT_CHANNELS"], 256);
  













  //SOLVER
  SetNode((*cfg)["SOLVER"], YAML::Node());
  SetNode((*cfg)["SOLVER"]["MAX_ITER"], 40000);
  SetNode((*cfg)["SOLVER"]["BASE_LR"], 0.001);
  SetNode((*cfg)["SOLVER"]["BASE_LR_FACTOR"], 2);
  SetNode((*cfg)["SOLVER"]["MOMENTUM"], 0.9);
  SetNode((*cfg)["SOLVER"]["WEIGHT_DECAY"], 0.0005);
  SetNode((*cfg)["SOLVER"]["WEIGHT_DECAY_BIAS"], 0);
  SetNode((*cfg)["SOLVER"]["GAMMA"], 0.1);
  SetNode((*cfg)["SOLVER"]["STEPS"], "(30000, )");
  SetNode((*cfg)["SOLVER"]["WARMUP_FACTOR"], 1.0 / 3.0);
  SetNode((*cfg)["SOLVER"]["WARMUP_ITERS"], 500);
  SetNode((*cfg)["SOLVER"]["WARMUP_METHOD"], "linear");
  SetNode((*cfg)["SOLVER"]["CHECKPOINT_PERIOD"], 2500);
  SetNode((*cfg)["SOLVER"]["IMS_PER_BATCH"], 2);

  //TEST
  SetNode((*cfg)["TEST"], YAML::Node());
  SetNode((*cfg)["TEST"]["EXPECTED_RESULTS"], "(,)");
  SetNode((*cfg)["TEST"]["EXPECTED_RESULTS_SIGMA_TOL"], 4);
  SetNode((*cfg)["TEST"]["IMS_PER_BATCH"], 8);
  SetNode((*cfg)["TEST"]["DETECTIONS_PER_IMG"], 100);

  //MISC OPTIONS
  SetNode((*cfg)["OUTPUT_DIR"], "../checkpoints");
  //default_config["PATH_CATALOG"], solver;
  SetNode((*cfg)["DTYPE"], "float32");
}
//用于访问config文件的模板类
template<typename T>
T GetCFG(std::initializer_list<const char*> node){
  if(!cfg){
    throw "Set Config file first";
  }
  std::vector<YAML::Node> tmp{*cfg};
  for(auto i = node.begin(); i != node.end(); ++i){
    tmp.push_back(tmp.back()[*i]);
  }
  return tmp.back().as<T>();
}
//不同的数据类型
template bool GetCFG<bool>(std::initializer_list<const char*> node);
template int64_t GetCFG<int64_t>(std::initializer_list<const char*> node);
template int GetCFG<int>(std::initializer_list<const char*> node);
template float GetCFG<float>(std::initializer_list<const char*> node);
template double GetCFG<double>(std::initializer_list<const char*> node);
template std::string GetCFG<std::string>(std::initializer_list<const char*> node);

template<>
std::vector<float> GetCFG<std::vector<float>>(std::initializer_list<const char*> node){
  if(!cfg){
    assert(false);
  }
  std::vector<YAML::Node> tmp{*cfg};
  for(auto i = node.begin(); i != node.end(); ++i){
    tmp.push_back(tmp.back()[*i]);
  }
  std::string svalue = tmp.back().as<std::string>();
  std::vector<float> elements;
  size_t pos = 0;
  //remove white spaces
  std::string::iterator end_pos = std::remove(svalue.begin(), svalue.end(), ' ');
  svalue.erase(end_pos, svalue.end());
  //remove ( and )
  svalue = svalue.substr(1, svalue.size()-2);
  std::string token;
  while ((pos = svalue.find(",")) != std::string::npos) {
    token = svalue.substr(0, pos);
    elements.push_back(std::stof(token));
    svalue.erase(0, pos + 1);
  }
  if(svalue.size() > 1){
    elements.push_back(std::stof(svalue));
  }
  return elements;
}

template<>
std::vector<int64_t> GetCFG<std::vector<int64_t>>(std::initializer_list<const char*> node){
  if(!cfg){
    assert(false);
  }
  std::vector<YAML::Node> tmp{*cfg};
  for(auto i = node.begin(); i != node.end(); ++i){
    tmp.push_back(tmp.back()[*i]);
  }
  std::string svalue = tmp.back().as<std::string>();
  std::vector<int64_t> elements;
  size_t pos = 0;
  //remove white spaces
  std::string::iterator end_pos = std::remove(svalue.begin(), svalue.end(), ' ');
  svalue.erase(end_pos, svalue.end());
  //remove ( and )
  svalue = svalue.substr(1, svalue.size()-2);
  
  std::string token;
  while ((pos = svalue.find(",")) != std::string::npos) {
    token = svalue.substr(0, pos);
    elements.push_back(std::stoi(token));
    svalue.erase(0, pos + 1);
  }
  if(svalue.size() > 1){
    elements.push_back(std::stoi(svalue));
  }
  return elements;
}

template<>
std::vector<std::string> GetCFG<std::vector<std::string>>(std::initializer_list<const char*> node){
  if(!cfg){
    throw "Set Config file first";
  }
  std::vector<YAML::Node> tmp{*cfg};
  for(auto i = node.begin(); i != node.end(); ++i){
    tmp.push_back(tmp.back()[*i]);
  }
  std::string svalue = tmp.back().as<std::string>();
  std::vector<std::string> splitted;
  // std::string svalue(name);
  if(svalue.find("(") != std::string::npos && svalue.find(")") != std::string::npos && std::count(svalue.begin(), svalue.end(), ',') > 0){
    
    size_t pos = 0;
    //remove white spaces
    std::string::iterator end_pos = std::remove(svalue.begin(), svalue.end(), ' ');
    svalue.erase(end_pos, svalue.end());
    end_pos = std::remove(svalue.begin(), svalue.end(), '"');
    svalue.erase(end_pos, svalue.end());
    //remove ( and )
    svalue = svalue.substr(1, svalue.size()-2);
    std::string token;
    while ((pos = svalue.find(",")) != std::string::npos) {
      token = svalue.substr(0, pos);
      splitted.push_back(token);
      svalue.erase(0, pos + 1);
    }
    if(svalue.size() > 1){
      splitted.push_back(svalue);
    }
  }
  return splitted;
}

}//mrcn
}//configs