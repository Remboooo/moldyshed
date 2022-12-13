from esphome import pins
import esphome.config_validation as cv
import esphome.codegen as cg
from esphome.const import CONF_ID, CONF_OUTPUT
from esphome.core import coroutine_with_priority
from esphome.components import output

status_led_ns = cg.esphome_ns.namespace("better_status_led")
BetterStatusLED = status_led_ns.class_("BetterStatusLED", cg.Component)

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(BetterStatusLED),
        cv.Required(CONF_OUTPUT): cv.use_id(output.FloatOutput)
    }
).extend(cv.COMPONENT_SCHEMA)


@coroutine_with_priority(80.0)
async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)

    out = await cg.get_variable(config[CONF_OUTPUT])
    cg.add(var.set_output(out))
