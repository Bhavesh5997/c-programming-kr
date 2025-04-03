#include <zephyr/device.h>
#include <stdio.h>
#include <zephyr/devicetree.h>

#define DT_DRV_COMPAT hello_driver

struct hello_config {
	const char *name;
        const char *label;
	const int an_inte;
};

static int hello_init(const struct device *dev)
{
	ARG_UNUSED(dev);
	const struct hello_config *cfg = dev->config;

	printf("Hello world %s\n", cfg->name);
        printf("Hello driver initialized: %s and int property %d\n", cfg->label, cfg->an_inte);

	return 0;
}

#define CREATE_HELLO_DEVICE(inst)                                  \
	static const struct hello_config hello_config_##inst = { \
		.name = DT_NODE_FULL_NAME(DT_INST(inst, DT_DRV_COMPAT)), \
		.label = DT_INST_PROP(inst, label),                        \
		.an_inte = DT_INST_PROP(inst, an_inte),                        \
	};                                                             \
	DEVICE_DT_INST_DEFINE(inst, hello_init, NULL,                 \
			NULL,                                    \
			&hello_config_##inst,                    \
			POST_KERNEL, CONFIG_KERNEL_INIT_PRIORITY_DEFAULT, \
			NULL);
DT_INST_FOREACH_STATUS_OKAY(CREATE_HELLO_DEVICE)
