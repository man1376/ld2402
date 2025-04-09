import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import binary_sensor
from esphome.const import CONF_NAME

CONF_TYPE = "type"
CONF_HLK_LD2402_ID = "hlk_ld2402_id"

hlk_ld2402_ns = cg.esphome_ns.namespace("hlk_ld2402")
HLKLD2402BinarySensor = hlk_ld2402_ns.class_("HLKLD2402BinarySensor", binary_sensor.BinarySensor)

BINARY_SENSOR_TYPES = ["presence", "motion"]

CONFIG_SCHEMA = binary_sensor.binary_sensor_schema(HLKLD2402BinarySensor).extend(
    {
        cv.Required(CONF_TYPE): cv.one_of(*BINARY_SENSOR_TYPES, lower=True),
        cv.GenerateID(CONF_HLK_LD2402_ID): cv.use_id(cg.Component),
    }
)

async def to_code(config):
    var = await binary_sensor.new_binary_sensor(config)
    await cg.register_component(var, config)
    parent = await cg.get_variable(config[CONF_HLK_LD2402_ID])
    cg.add(var.set_parent(parent))
    cg.add(var.set_type(config[CONF_TYPE]))